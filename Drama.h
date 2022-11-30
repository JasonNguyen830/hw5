//
// Created by USER on 11/28/2022.
//

#ifndef HW5_DRAMA_H
#define HW5_DRAMA_H
#include "Movie.h"

class Drama : public Movie{
public:
    Drama();
    ~Drama();
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

    bool operator==(const Movie& movie) const;
    bool operator!=(const Movie& movie) const;

    bool operator>(const Movie& movie) const;
    bool operator<(const Movie& movie) const;
};


#endif //HW5_DRAMA_H
