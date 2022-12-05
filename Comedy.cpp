//
// Created by USER on 11/28/2022.
//

#include "Comedy.h"

Comedy::Comedy(std::string title, std::string year) {
    setTitle(std::move(title));
    setYear(year);
}

Comedy::Comedy() = default;

Comedy::~Comedy() = default;

char Comedy::getChar() const {
    return 'F';
}

bool Comedy::setStock(int stock) {
    this->stock = stock;
    return true;
}

bool Comedy::setDirector(std::string director) {
    this->director = director;
    return true;
}

bool Comedy::setTitle(std::string title) {
    this->title = title;
    return true;
}

bool Comedy::setYear(std::string year) {
    this->year = year;
    return true;
}

int Comedy::getStock() const {
    return this->stock;
}

std::string Comedy::getDirector() const {
    return this->director;
}

std::string Comedy::getTitle() const {
    return this->title;
}

std::string Comedy::getYear() const {
    return this->year;
}

std::string Comedy::getLog() const {
    return getTitle() + " " + getYear();
}

bool Comedy::operator==(const Movie &movie) const {
    return (title == movie.getTitle()) && (year == movie.getYear());
}

bool Comedy::operator!=(const Movie &movie) const {
    return (this == &movie);
}

bool Comedy::operator>(const Movie &movie) const {
    if (title > movie.getTitle()) {
        return true;
    } else {
        if (year > movie.getYear()) {
            return true;
        }
    }
    return false;
}

bool Comedy::operator<(const Movie &movie) const {
    if (this == &movie) {
        return false;
    }
    if (this > &movie) {
        return false;
    }

    return true;
}
