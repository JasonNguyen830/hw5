// Jason Nguyen + Thaddeus Gonzalez-Serna
// HW 5

#ifndef HW5_MOVIE_H
#define HW5_MOVIE_H

#include <iostream>
#include <ostream>
#include <string>

class Movie {
    // Outputs movie contents
    friend std::ostream& operator <<(std::ostream& ostream, const Movie& movie);
public:
    enum MOVIES {COMEDY, CLASSICS, DRAMA, END};
    Movie(); // Constructor
    virtual ~Movie(); // Deconstructor

    // Setter functions
    virtual bool setStock(int stock) = 0;
    virtual bool setDirector(std::string director) = 0;
    virtual bool setTitle(std::string title) = 0;
    virtual bool setYear(std::string year) = 0;
    virtual bool setActor(std::string actor) = 0;
    virtual bool setReleaseDate(std::string date) = 0;
    bool setOtherMovie(Movie*& movie);

    // Getter functions
    virtual int getStock() const = 0;
    virtual std::string getDirector() const = 0;
    virtual std::string getTitle() const = 0;
    virtual std::string getYear() const = 0;
    virtual char getChar() const = 0;
    virtual std::string getLog() const = 0;
    Movie* getOtherMovie() const;
    virtual std::string getMajor() const = 0;
    virtual std::string getReleaseDate() const = 0;

    // Operator overloads
    virtual bool operator==(const Movie& movie) const = 0;
    virtual bool operator!=(const Movie& movie) const = 0;

    virtual bool operator>(const Movie& movie) const = 0;
    virtual bool operator<(const Movie& movie) const = 0;

protected:
    int stock;
    std::string director;
    std::string title;
    std::string year;
    Movie* other;
    std::string majorActor;
    std::string releaseDate;

};


#endif //HW5_MOVIE_H
