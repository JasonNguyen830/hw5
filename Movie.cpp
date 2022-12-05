//
// Created by USER on 11/23/2022.
//

#include "Movie.h"

Movie::Movie() {
    other = nullptr;
}

std::ostream &operator<<(std::ostream &ostream, const Movie &movie) {
    ostream << "\tStock [" << movie.getStock() << "] \n";
    ostream << "\tDirector [" << movie.getDirector() << "] \n";
    ostream << "\tTitle [" << movie.getTitle() << "] \n";
    ostream << "\tYear [" << movie.getYear() << "] \n";

    return ostream;
}

bool Movie::setOtherMovie(Movie *&movie) {
    other = movie;
    return true;
}

Movie *Movie::getOtherMovie() const {
    return other;
}
