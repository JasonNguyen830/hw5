// Jason Nguyen + Thaddeus Gonzalez-Serna
// HW 5
#ifndef HW5_MOVIEKEY_H
#define HW5_MOVIEKEY_H
#include "Movie.h"
#include <string>

class MovieKey {
public:
    MovieKey(); // Constructor
    ~MovieKey() = default; // Deconstructor
    void setTitle(std::string title); // Sets title
    void setMovie(Movie*& movie); // Sets movie object

    Movie* getMovie() const; // Gets movie object
    std::string getTitle() const; // Gets title
    // Compares movie objects
    bool operator==(const std::string & rhs) const;
    int hash() const; // Hash
private:
    std::string title; // title of movie
    Movie* movie; // Movie object
};


#endif //HW5_MOVIEKEY_H
