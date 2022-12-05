//
// Created by USER on 11/28/2022.
//

#include "ReturnTransaction.h"

ReturnTransaction::ReturnTransaction() = default;

void ReturnTransaction::execute() {
    if (movie != nullptr) {
        executeReturn(*movie);
    }
}

bool ReturnTransaction::executeReturn(Movie &movie) {
    if (borrowed) {
        return movie.setStock(movie.getStock() + 1);
    } else {
        std::cout << "Can't return item" << std::endl;
        return false;
    }
}

std::string ReturnTransaction::getLogOfTrans() const {
    if (movie != nullptr) {
        return "Returned " + movie->getTitle();
    }
    return "";
}
