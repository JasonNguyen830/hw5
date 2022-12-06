// Jason Nguyen + Thaddeus Gonzalez-Serna
// HW 5

#ifndef HW5_COMEDY_H
#define HW5_COMEDY_H
#include "Movie.h"
#include <fstream>
#include <sstream>
#include <string>

class Comedy : public Movie{
public:
    Comedy(std::string title, std::string year); //constructor
    Comedy(); // constructor
    ~Comedy() = default; // deconstructor
    char getChar() const; // Gets the character of movie 'F'

    // Setter functions
    bool setStock(int stock);
    bool setDirector(std::string director);
    bool setTitle(std::string title);
    bool setYear(std::string year);
    bool setActor(std::string actor);
    bool setReleaseDate(std::string date);

    // Getter functions
    int getStock() const;
    std::string getDirector() const;
    std::string getTitle() const;
    std::string getYear() const;
    std::string getLog() const;
    std::string getMajor() const;
    std::string getReleaseDate() const;

    // Overloaded functions
    bool operator==(const Movie& movie) const;
    bool operator!=(const Movie& movie) const;

    bool operator>(const Movie& movie) const;
    bool operator<(const Movie& movie) const;


};


#endif //HW5_COMEDY_H
