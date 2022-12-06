// Jason Nguyen + Thaddeus Gonzalez-Serna
// HW 5

#include "Comedy.h"

// Constructor
Comedy::Comedy(std::string title, std::string year) {
    title = std::move(title);
    year  = std::move(year);
}

// Constructor
Comedy::Comedy() = default;

// Returns character of movie 'F'
char Comedy::getChar() const {
    return 'F';
}

// Sets the stock and returns true
bool Comedy::setStock(int stock) {
    this->stock = std::move(stock);
    return true;
}

// Sets the director and returns true
bool Comedy::setDirector(std::string director) {
    this->director = std::move(director);
    return true;
}

// Sets the title and returns true
bool Comedy::setTitle(std::string title) {
    this->title = std::move(title);
    return true;
}

// Sets the year and returns true
bool Comedy::setYear(std::string year) {
    this->year = std::move(year);
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

    bool ret_val = false;

    if (title > movie.getTitle()) {
        //return true;
        ret_val = true;
    } else {
        if (year > movie.getYear()) {
            //return true;
            ret_val = true;
        }
    }
    //return false;
    return ret_val;
}

// Overloaded operator comparing movies
bool Comedy::operator<(const Movie &movie) const {

    bool ret_val = true;

    if (this == &movie) {
        //return false;
        ret_val = false;
    }
    if (this > &movie) {
        //return false;
        ret_val = false;
    }

    return ret_val;
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
