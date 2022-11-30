//
// Created by USER on 11/28/2022.
//

#ifndef HW5_MOVIEFACTORY_H
#define HW5_MOVIEFACTORY_H
#include "Movie.h"
#include "Comedy.h"
#include "Classic.h"
#include "Drama.h"

const char COMEDY = 'F';
const char CLASSIC = 'C';
const char DRAMA = 'D';

class MovieFactory {
public:
    MovieFactory();
    ~MovieFactory();
    static Movie* createMovie(const char type);
};


#endif //HW5_MOVIEFACTORY_H
