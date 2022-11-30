//
// Created by USER on 11/28/2022.
//

#ifndef HW5_MOVIEKEY_H
#define HW5_MOVIEKEY_H
#include "Movie.h"
#include <string>

class MovieKey {
public:
    MovieKey();
    ~MovieKey();
    void setTitle(std::string title);
    void setMovie(Movie*& movie);

    Movie* getMovie() const;
    std::string getTitle() const;
    bool operator==(const std::string rhs) const;
    int hash() const;
private:
    std::string title;
    Movie* movie;
};


#endif //HW5_MOVIEKEY_H
