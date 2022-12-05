// Jason Nguyen + Thaddeus Gonzalez-Serna
// HW 5

#ifndef HW5_DRAMA_H
#define HW5_DRAMA_H
#include "Movie.h"

class Drama : public Movie{
public:
    Drama(); // Constructor
    ~Drama(); // Deconstructor
    char getChar() const; // Returns character of movie 'D'

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

    // Overloaded operator functions
    bool operator==(const Movie& movie) const;
    bool operator!=(const Movie& movie) const;

    bool operator>(const Movie& movie) const;
    bool operator<(const Movie& movie) const;
};


#endif //HW5_DRAMA_H
