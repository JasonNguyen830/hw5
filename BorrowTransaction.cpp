//
// Created by USER on 11/30/2022.
//

#include "BorrowTransaction.h"

BorrowTransaction::BorrowTransaction() {

}

BorrowTransaction::~BorrowTransaction() {

}

void BorrowTransaction::execute() {
    if (movie != nullptr) {
        if(movie->getChar() == 'C') {
            borrowClassic(*movie);
        } else {
            borrow(*movie);
        }
    }
}

bool BorrowTransaction::borrow(Movie &movie) {
    if (movie.getStock() > 0) {
        bool success = movie.setStock(movie.getStock() - 1);
        if (success) {
            borrowed = true;
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool BorrowTransaction::borrowClassic(Movie &movie) {
    if (movie.getStock() == 0 && (movie.getOtherMovie() == nullptr || movie.getOtherMovie()->getStock()== 0)) {
        return false;
    }
    if (movie.getStock() >0) {
        return movie.setStock(movie.getStock() - 1);
    } else {
        int otherStock = movie.getOtherMovie()->getStock();
        return movie.getOtherMovie()->setStock(otherStock - 1);
    }
}

std::string BorrowTransaction::getLogOfTrans() const {
    if (movie != nullptr) {
        return "Borrowed " + movie->getTitle();
    }
    return "";
}
