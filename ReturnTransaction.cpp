// Jason Nguyen + Thaddeus Gonzalez-Serna
// HW 5

#include "ReturnTransaction.h"

// Constructor
ReturnTransaction::ReturnTransaction() = default;

// Executes return transaction if the movie is not null
void ReturnTransaction::execute() {
    if (movie != nullptr) {
        executeReturn(*movie);
    }
}

// Executes the return transaction of the movie was borrowed
bool ReturnTransaction::executeReturn(Movie &movie) {
    if (borrowed) {
        return movie.setStock(movie.getStock() + 1);
    } else {
        std::cout << "Can't return " << movie.getTitle() << std::endl;
        return false;
    }
}

// Returns the movie transaction if movie was not null
std::string ReturnTransaction::getLogOfTrans() const {
    if (movie != nullptr) {
        return "Returned " + movie->getTitle();
    }
    return "";
}
