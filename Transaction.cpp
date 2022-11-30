//
// Created by USER on 11/28/2022.
//

#include "Transaction.h"

Transaction::Transaction() {
    movieTreeReference = NULL;
}

Transaction::~Transaction() {

}

void Transaction::setMovie(std::set<Movie *> movieTree[]) {
    movieTreeReference = movieTree;
}
