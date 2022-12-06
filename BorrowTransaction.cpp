// Jason Nguyen + Thaddeus Gonzalez-Serna
// HW 5

#include "BorrowTransaction.h"

// Constructor
BorrowTransaction::BorrowTransaction() = default;

// Executes the borrow action
void BorrowTransaction::execute() {
    if (movie != nullptr) {
        if(movie->getChar() == 'C') {
            borrowClassic(*movie);
        } else {
            borrow(*movie);
        }
    }
}

// Borrows a movie from the collection
// Returns false if the movie has stock > 0
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

// Borrows a classic movie
bool BorrowTransaction::borrowClassic(Movie &movie) {
    if (movie.getStock() == 0 && (movie.getOtherMovie() == nullptr || movie.getOtherMovie()->getStock()== 0)) {
        return false;
    }
    if (movie.getStock() >0) {
        return movie.setStock(movie.getStock() - 1);
    } else {
        int other_stock = movie.getOtherMovie()->getStock();
        return movie.getOtherMovie()->setStock(other_stock - 1);
    }
}

// Gets transaction log
std::string BorrowTransaction::getLogOfTrans() const {
    if (movie != nullptr) {
        return "Borrowed " + movie->getTitle();
    }
    return "";
}
