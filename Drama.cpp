//
// Created by USER on 11/28/2022.
//

#include "Drama.h"

Drama::Drama() {

}

Drama::~Drama() {

}

char Drama::getChar() const {
    return 'D';
}

bool Drama::setStock(int stock) {
    this->stock = stock;
    return false;
}

bool Drama::setDirector(std::string director) {
    this->director = director;
    return false;
}

bool Drama::setTitle(std::string title) {
    this->title = title;
    return false;
}

bool Drama::setYear(std::string year) {
    this->year = year;
    return false;
}

int Drama::getStock() const {
    return this->stock;
}

std::string Drama::getDirector() const {
    return this->director;
}

std::string Drama::getTitle() const {
    return this->title;
}

std::string Drama::getYear() const {
    return this->year;
}

std::string Drama::getLog() const {
    return " ";
}

bool Drama::operator==(const Movie &movie) const {
    return (director == movie.getDirector()) && (title == movie.getTitle());
}

bool Drama::operator!=(const Movie &movie) const {
    return (this == &movie);
}

bool Drama::operator>(const Movie &movie) const {
    if (title > movie.getTitle()) {
        return true;
    } else {
        if (year > movie.getYear()) {
            return true;
        }
    }
    return false;
}

bool Drama::operator<(const Movie &movie) const {
    if (this == &movie) {
        return false;
    }
    if (this > &movie) {
        return false;
    }

    return true;
}
