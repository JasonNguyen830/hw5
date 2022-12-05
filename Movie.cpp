// Jason Nguyen + Thaddeus Gonzalez-Serna
// HW 5

#include "Movie.h"

// Constructor
Movie::Movie() {
    other = NULL;
}

// Deconstructor
Movie::~Movie() {

}

// Outputs the movie information for Comedy, Classic, and Drama movies
std::ostream &operator<<(std::ostream &ostream, const Movie &movie) {
    if (movie.getChar() == 'F' || movie.getChar() == 'D') {
        ostream << "\tStock [" << movie.getStock() << "] \n";
        ostream << "\tDirector [" << movie.getDirector() << "] \n";
        ostream << "\tTitle [" << movie.getTitle() << "] \n";
        ostream << "\tYear [" << movie.getYear() << "] \n";
    } else {
        ostream << "\tStock [" << movie.getStock() << "] \n";
        ostream << "\tDirector [" << movie.getDirector() << "] \n";
        ostream << "\tTitle [" << movie.getTitle() << "] \n";
        ostream << "\tMajor Actor/Actress [" << movie.getMajor() << "] \n";
        ostream << "\tRelease Date [" << movie.getReleaseDate() << "] \n";
    }

    return ostream;
}

// Sets other movie and returns true
bool Movie::setOtherMovie(Movie *&movie) {
    other = movie;
    return true;
}

// Gets other movie and returns true
Movie *Movie::getOtherMovie() const {
    return other;
}
