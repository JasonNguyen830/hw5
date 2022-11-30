//
// Created by USER on 11/28/2022.
//

#ifndef HW5_CLASSIC_H
#define HW5_CLASSIC_H
#include "Movie.h"
#include <fstream>
#include <sstream>
#include <string>

class Classic : public Movie {
public:
    Classic();
    ~Classic();
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

private:
    std::string majorActor;
    std::string releaseDate;
    void setActorAndDate();
};


#endif //HW5_CLASSIC_H
