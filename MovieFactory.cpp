//
// Created by USER on 11/28/2022.
//

#include "MovieFactory.h"
#include <iostream> //place holder remove
MovieFactory::MovieFactory() = default;

Movie *MovieFactory::createMovie(const char type) {
    Movie* ret_val = nullptr;
    switch (type) {
        case COMEDY:
            ret_val = new Comedy;
            std::cout<< "Making comedy"<<std::endl;
            break;
        case CLASSIC:
            ret_val = new Classic;
            std::cout<< "Making classic"<<std::endl;
            break;
        case DRAMA:
            ret_val = new Drama;
            std::cout<< "Making Drama"<<std::endl;
            break;
        default:
            ret_val = nullptr;
            break;
    }
    return ret_val;
}
