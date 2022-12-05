//
// Created by USER on 11/28/2022.
//

#include "Transaction.h"

Transaction::Transaction() {
    movieTreeReference = nullptr;
}

void Transaction::setMovie(std::set<Movie *> movieTree[]) {
    movieTreeReference = movieTree;
}
