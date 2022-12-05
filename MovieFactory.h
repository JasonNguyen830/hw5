// Jason Nguyen + Thaddeus Gonzalez-Serna
// HW 5

#ifndef HW5_MOVIEFACTORY_H
#define HW5_MOVIEFACTORY_H
#include "Movie.h"
#include "Comedy.h"
#include "Classic.h"
#include "Drama.h"

const char COMEDY = 'F'; // Comedy
const char CLASSIC = 'C'; // Classic
const char DRAMA = 'D'; // Drama

class MovieFactory {
public:
    MovieFactory(); // Constructor
    ~MovieFactory(); // Deconstructor
    static Movie* createMovie(const char type); // Creates movie object
};


#endif //HW5_MOVIEFACTORY_H
