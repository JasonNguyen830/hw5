//
// Created by USER on 11/28/2022.
//

#include "Classic.h"

Classic::Classic() = default;

Classic::~Classic() = default;

char Classic::getChar() const {
    return 'C';
}

bool Classic::setStock(int stock) {
    this->stock = stock;
    return false;
}

bool Classic::setDirector(std::string director) {
    this->director = director;
    return false;
}

bool Classic::setTitle(std::string title) {
    this->title = title;
    return false;
}

bool Classic::setYear(std::string year) {
    this->year = year;
    setActorAndDate();
    return false;
}

int Classic::getStock() const {
    return this->stock;
}

std::string Classic::getDirector() const {
    return this->director;
}

std::string Classic::getTitle() const {
    return this->title;
}

std::string Classic::getYear() const {
    return this->year;
}

std::string Classic::getLog() const {
    return this->majorActor + " " + this->releaseDate;
}

bool Classic::operator==(const Movie &movie) const {
    return (director == movie.getDirector()) &&
    (title == movie.getTitle());
}

bool Classic::operator!=(const Movie &movie) const {
    return this != &movie;
}

bool Classic::operator>(const Movie &movie) const {
    const auto *const movie2 = dynamic_cast<const Classic*>(&movie);
    if (releaseDate > movie2->releaseDate) {
        return true;
    } else {
        if (majorActor > movie2->majorActor) {
            return true;
        }
    }
    return false;
}

bool Classic::operator<(const Movie &movie) const {
    if (this == &movie) {
        return false;
    }
    if (this > &movie) {
        return false;
    }

    return true;
}

void Classic::setActorAndDate() {
    std::string line = getYear();
    std::stringstream stream(line);
    std::string f_name;
    std::string l_name;
    std::string day;
    std::string year;
    
    stream >> f_name;
    stream >> l_name;
    stream >> day;
    stream >> year;
    majorActor = f_name + " " + l_name;
    releaseDate = day + " " + year;
}
