// Jason Nguyen + Thaddeus Gonzalez-Serna
// HW 5

#ifndef HW5_CLASSIC_H
#define HW5_CLASSIC_H
#include "Movie.h"
#include <fstream>
#include <sstream>
#include <string>

class Classic : public Movie {
public:
    Classic(); // Constructor
    ~Classic(); // Deconstructor
    char getChar() const; // Gets character of classic movies 'C'

    bool setStock(int stock); // Sets the stock
    bool setDirector(std::string director); // Sets the director name
    bool setTitle(std::string title); // Sets the title
    bool setYear(std::string year); // Sets the year
    bool setActor(std::string actor); // Sets the major actor/actress and returns true
    bool setReleaseDate(std::string date); // Sets the release date and returns true;

    int getStock() const; // Returns the stock
    std::string getDirector() const; // Returns the director
    std::string getTitle() const; // Returns the title
    std::string getYear() const; // Returns the year
    std::string getLog() const; // Returns the log
    std::string getMajor() const; // Returns the major actor/actress
    std::string getReleaseDate() const; // Returns the release date


    // Overloaded functions
    bool operator==(const Movie& movie) const;
    bool operator!=(const Movie& movie) const;

    bool operator>(const Movie& movie) const;
    bool operator<(const Movie& movie) const;
};


#endif //HW5_CLASSIC_H
