// Jason Nguyen + Thaddeus Gonzalez-Serna
// HW 5

#include "Comedy.h"

// Constructor
Comedy::Comedy(std::string title, std::string year) {
    setTitle(title);
    setYear(year);
}

// Constructor
Comedy::Comedy() {

}

// Deconstructor
Comedy::~Comedy() {

}

// Returns character of movie 'F'
char Comedy::getChar() const {
    return 'F';
}

// Sets the stock and returns true
bool Comedy::setStock(int stock) {
    this->stock = stock;
    return true;
}

// Sets the director and returns true
bool Comedy::setDirector(std::string director) {
    this->director = director;
    return true;
}

// Sets the title and returns true
bool Comedy::setTitle(std::string title) {
    this->title = title;
    return true;
}

// Sets the year and returns true
bool Comedy::setYear(std::string year) {
    this->year = year;
    return true;
}

// Returns the stock
int Comedy::getStock() const {
    return this->stock;
}

// Returns the director
std::string Comedy::getDirector() const {
    return this->director;
}

// Returns the title
std::string Comedy::getTitle() const {
    return this->title;
}

// Returns the year
std::string Comedy::getYear() const {
    return this->year;
}

// Returns the log
std::string Comedy::getLog() const {
    return getTitle() + " " + getYear();
}

// Overloaded operator comparing movies
bool Comedy::operator==(const Movie &movie) const {
    return (title == movie.getTitle()) && (year == movie.getYear());
}

// Overloaded operator comparing movies
bool Comedy::operator!=(const Movie &movie) const {
    return (this == &movie);
}

// Overloaded operator comparing movie alphabetization and year
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

// Overloaded operator comparing movies
bool Comedy::operator<(const Movie &movie) const {
    if (this == &movie) {
        return false;
    }
    if (this > &movie) {
        return false;
    }

    return true;
}

// Returns major actor (should be empty)
std::string Comedy::getMajor() const {
    return this->majorActor;
}

// Returns release date (should be empty)
std::string Comedy::getReleaseDate() const {
    return this->releaseDate;
}

// Sets the actor and returns true
bool Comedy::setActor(std::string actor) {
    this->majorActor = actor;
    return true;
}

// Sets the release date and returns true
bool Comedy::setReleaseDate(std::string date) {
    this->releaseDate = date;
    return true;
}
