//
// Created by USER on 11/28/2022.
//

#ifndef HW5_COMEDY_H
#define HW5_COMEDY_H
#include "Movie.h"
#include <fstream>
#include <sstream>
#include <string>

class Comedy : public Movie{
public:
    Comedy(std::string title, std::string year);
    Comedy();
    ~Comedy();
    char getChar() const;

    bool setStock(int stock);
    bool setDirector(std::string director);
    bool setTitle(std::string title);
    bool setYear(std::string year);

    int getStock() const;
    std::string getDirector() const;
    std::string getTitle() const;
    std::string getYear() const;
    std::string getLog() const;

    virtual bool operator==(const Movie& movie) const;
    virtual bool operator!=(const Movie& movie) const;

    bool operator>(const Movie& movie) const;
    bool operator<(const Movie& movie) const;
};


#endif //HW5_COMEDY_H
