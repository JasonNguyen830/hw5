// Jason Nguyen + Thaddeus Gonzalez-Serna
// HW 5

#include "MovieKey.h"
#include<iostream>
// Constructor
MovieKey::MovieKey() = default;

// Sets the title
void MovieKey::setTitle(std::string title) {
    this->title = std::move(title);
}

// Sets the movie
void MovieKey::setMovie(Movie *&movie) {
    this->movie = movie;
}

// Returns movie object
Movie *MovieKey::getMovie() const {
    return movie;
}

// Returns title
std::string MovieKey::getTitle() const {
    return title;
}

// Returns true if movies and given argument are the same
bool MovieKey::operator==(const std::string & rhs) const {
    return title == rhs;
}

// Hash
int MovieKey::hash() const {
    int val = 0;
    for ( char i: title /*int i = 0; i < title.size(); i++ */ ) {
        std::cout << "val "<< val <<std::endl;
        val += i; // title[i];
    }
    return val;
}
