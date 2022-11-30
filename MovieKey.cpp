//
// Created by USER on 11/28/2022.
//

#include "MovieKey.h"

MovieKey::MovieKey() {

}

MovieKey::~MovieKey() {

}

void MovieKey::setTitle(std::string title) {
    this->title = title;
}

void MovieKey::setMovie(Movie *&movie) {
    this->movie = movie;
}

Movie *MovieKey::getMovie() const {
    return movie;
}

std::string MovieKey::getTitle() const {
    return title;
}

bool MovieKey::operator==(const std::string rhs) const {
    return title == rhs;
}

int MovieKey::hash() const {
    int val = 0;
    for (int i = 0; i <title.size(); i++) {
        val += title[i];
    }
    return val;
}
