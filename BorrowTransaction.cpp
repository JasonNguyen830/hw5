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
    bool ret_val = false;
    if (movie.getStock() > 0) {
        bool success = movie.setStock(movie.getStock() - 1);
        if (success) {
            borrowed = true;
            //return true;
            ret_val = true;
        } 
    }
    return ret_val;
}

// Borrows a classic movie
bool BorrowTransaction::borrowClassic(Movie &movie) {
    bool ret_val = false;

    bool not_available = movie.getStock() == 0 && (movie.getOtherMovie() == nullptr || movie.getOtherMovie()->getStock()== 0);
    if (not_available) {
        //return false;
        ret_val = false;
    }
    if (movie.getStock() > 0 && !not_available ) {
        //return movie.setStock(movie.getStock() - 1);
        ret_val = movie.setStock(movie.getStock() - 1);
    } else {
        int other_stock = movie.getOtherMovie()->getStock();
        //return movie.getOtherMovie()->setStock(other_stock - 1);
        ret_val = movie.getOtherMovie()->setStock(other_stock - 1);
    }

    return ret_val;
}

// Gets transaction log
std::string BorrowTransaction::getLogOfTrans() const {
    if (movie != nullptr) {
        return "Borrowed " + movie->getTitle();
    }
    return "";
}
