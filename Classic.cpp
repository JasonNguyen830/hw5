// Jason Nguyen + Thaddeus Gonzalez-Serna
// HW 5

#include "Classic.h"

// Constructor
Classic::Classic() = default;

// Gets character of classic movies 'C'
char Classic::getChar() const {
    return 'C';
}

// Sets the stock
bool Classic::setStock(int stock) {
    if(stock >= 0 ){
    this->stock = stock;
    }
    return false;
}

// Sets the director name
bool Classic::setDirector(std::string director) {
    this->director = std::move(director);
    return false;
}

// Sets the title
bool Classic::setTitle(std::string title) {
    this->title = std::move(title);
    return false;
}

// Sets the year
bool Classic::setYear(std::string year) {
    this->year = std::move(year);
    return false;
}

// Returns the stock
int Classic::getStock() const {
    return this->stock;
}

// Returns the director
std::string Classic::getDirector() const {
    return this->director;
}

// Returns the title
std::string Classic::getTitle() const {
    return this->title;
}

// Returns the year
std::string Classic::getYear() const {
    return this->year;
}

// Returns the log
std::string Classic::getLog() const {
    return this->majorActor + " " + this->releaseDate;
}

// Overload function for ==
// Returns true if the director and title name match
bool Classic::operator==(const Movie &movie) const {
    return (director == movie.getDirector()) &&
    (title == movie.getTitle());
}

// Overload function for !=
// Returns true if this does not equal to the movie
bool Classic::operator!=(const Movie &movie) const {
    return this != &movie;
}

// Overload function for >
// Returns true if the release date is greater than the movie release date
// Returns true if the major actors is greater (first in alphabet) than movie actor
bool Classic::operator>(const Movie &movie) const {
    const auto *const movie2 = dynamic_cast<const Classic*>(&movie);

    bool ret_val = false;
    if (releaseDate > movie2->releaseDate) {
        ret_val =  true;
    } else {
        if (majorActor > movie2->majorActor) {
            ret_val = true;
        }
    }
    return ret_val;
}

// Operative overload for <
// Returns false if movies are the same, or if current movie is greater than given movie
bool Classic::operator<(const Movie &movie) const {
    if (this == &movie) {
        return false;
    }
    if (this > &movie) {
        return false;
    }

    return true;
}

// Returns the major actor/actress
std::string Classic::getMajor() const {
    return this->majorActor;
}

// Returns the release date
std::string Classic::getReleaseDate() const {
    return this->releaseDate;
}

// Sets the major actor/actress and returns true
bool Classic::setActor(std::string actor) {
    this->majorActor = actor;
    return true;
}

// Sets the release date and returns true;
bool Classic::setReleaseDate(std::string date) {
    this->releaseDate = date;
    return true;
}
