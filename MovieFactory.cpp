//
// Created by USER on 11/28/2022.
//

#include "MovieFactory.h"

MovieFactory::MovieFactory() {

}

MovieFactory::~MovieFactory() {

}

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
