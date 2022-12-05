// Jason Nguyen + Thaddeus Gonzalez-Serna
// HW 5

#ifndef HW5_TRANSACTION_H
#define HW5_TRANSACTION_H
#include <set>
#include <algorithm>
#include "Movie.h"
#include "Customer.h"

class Transaction {
public:
    Transaction(); // Constructor
    ~Transaction(); // Deconstructor

    // Sets up the movie
    void setMovie(std::set<Movie*> movieTree[]);
    virtual void execute() = 0; // Execute functions

protected:
    std::set<Movie*>* movieTreeReference; // Contains list of movies
};


#endif //HW5_TRANSACTION_H
