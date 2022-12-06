// Jason Nguyen + Thaddeus Gonzalez-Serna
// HW 5

#include "Transaction.h"

// Constructor
Transaction::Transaction() {
    movieTreeReference = nullptr;
}

// Sets the movie
void Transaction::setMovie(std::set<Movie *> movieTree[]) {
    movieTreeReference = movieTree;
}
