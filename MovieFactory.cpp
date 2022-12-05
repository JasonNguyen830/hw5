// Jason Nguyen + Thaddeus Gonzalez-Serna
// HW 5

#include "MovieFactory.h"

// Constructor
MovieFactory::MovieFactory() {

}

// Deconstructor
MovieFactory::~MovieFactory() {

}

// Creates a movie object based on it's respective typing
Movie *MovieFactory::createMovie(const char type) {
    Movie* retVal = nullptr;
    switch (type) {
        case COMEDY:
            retVal = new Comedy;
            break;
        case CLASSIC:
            retVal = new Classic;
            break;
        case DRAMA:
            retVal = new Drama;
            break;
        default:
            retVal = nullptr;
            break;
    }
    return retVal;
}
