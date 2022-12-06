// Jason Nguyen + Thaddeus Gonzalez-Serna
// HW 5

#include "MovieFactory.h"

// Constructor
MovieFactory::MovieFactory() = default;

// Creates a movie object based on it's respective typing
Movie *MovieFactory::createMovie(const char type) {
    Movie* ret_val = nullptr;
    switch (type) {
        case COMEDY:
            ret_val = new Comedy;
            break;
        case CLASSIC:
            ret_val = new Classic;
            break;
        case DRAMA:
            ret_val = new Drama;
            break;
        default:
            ret_val = nullptr;
            break;
    }
    return  ret_val;
}
