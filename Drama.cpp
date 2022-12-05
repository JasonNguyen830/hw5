// Jason Nguyen + Thaddeus Gonzalez-Serna
// HW 5

#include "Drama.h"

// Constructor
Drama::Drama() {

}

// Deconstructor
Drama::~Drama() {

}

// Returns the character of movie 'D'
char Drama::getChar() const {
    return 'D';
}

// Sets the stock and returns true
bool Drama::setStock(int stock) {
    this->stock = stock;
    return true;
}

// Sets the director and returns true
bool Drama::setDirector(std::string director) {
    this->director = director;
    return true;
}

// Sets title and returns true
bool Drama::setTitle(std::string title) {
    this->title = title;
    return false;
}

// Sets year and returns true
bool Drama::setYear(std::string year) {
    this->year = year;
    return false;
}

// Returns stock
int Drama::getStock() const {
    return this->stock;
}

// Returns director
std::string Drama::getDirector() const {
    return this->director;
}

// Returns the title
std::string Drama::getTitle() const {
    return this->title;
}

// Returns the year
std::string Drama::getYear() const {
    return this->year;
}

// Returns the log
std::string Drama::getLog() const {
    return " ";
}

// Overloaded operator comparing movies
bool Drama::operator==(const Movie &movie) const {
    return (director == movie.getDirector()) && (title == movie.getTitle());
}

// Overloaded operator comparing movies
bool Drama::operator!=(const Movie &movie) const {
    return (this == &movie);
}

// Overloaded operator comparing movies alphabetization and year
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

// Overloaded operator comparing movies
bool Drama::operator<(const Movie &movie) const {
    if (this == &movie) {
        return false;
    }
    if (this > &movie) {
        return false;
    }

    return true;
}

// Returns major actor/actress (should be empty)
std::string Drama::getMajor() const {
    return this->majorActor;
}

// Returns release date (should be empty)
std::string Drama::getReleaseDate() const {
    return this->releaseDate;
}

// Sets the major actor/actress and returns true
bool Drama::setActor(std::string actor) {
    this->majorActor = actor;
    return true;
}

// Sets the release date and returns true
bool Drama::setReleaseDate(std::string date) {
    this->releaseDate = date;
    return true;
}
