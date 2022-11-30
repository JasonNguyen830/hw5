//
// Created by USER on 11/28/2022.
//

#ifndef HW5_TRANSACTION_H
#define HW5_TRANSACTION_H
#include <set>
#include <algorithm>
#include "Movie.h"
#include "Customer.h"

class Transaction {
public:
    Transaction();
    ~Transaction();

    void setMovie(std::set<Movie*> movieTree[]);
    virtual void execute() = 0;

protected:
    std::set<Movie*>* movieTreeReference;
};


#endif //HW5_TRANSACTION_H
