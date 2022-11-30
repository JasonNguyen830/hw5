//
// Created by USER on 11/23/2022.
//

#ifndef HW5_MOVIE_H
#define HW5_MOVIE_H

#include <iostream>
#include <ostream>
#include <string>

class Movie {
    friend std::ostream& operator <<(std::ostream& ostream, const Movie& movie);
public:
    enum MOVIES {COMEDY, CLASSICS, DRAMA, END};
    Movie();
    virtual ~Movie();

    virtual bool setStock(int stock) = 0;
    virtual bool setDirector(std::string director) = 0;
    virtual bool setTitle(std::string title) = 0;
    virtual bool setYear(std::string year) = 0;
    bool setOtherMovie(Movie*& movie);

    virtual int getStock() const = 0;
    virtual std::string getDirector() const = 0;
    virtual std::string getTitle() const = 0;
    virtual std::string getYear() const = 0;
    virtual char getChar() const = 0;
    virtual std::string getLog() const = 0;
    Movie* getOtherMovie() const;

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

};


#endif //HW5_MOVIE_H
