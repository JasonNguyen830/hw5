//
// Created by USER on 11/23/2022.
//

#ifndef HW5_BLOCKBUSTER_H
#define HW5_BLOCKBUSTER_H
#include <algorithm>
#include <set>
#include "InputProcessor.h"
#include "Transaction.h"
#include "Movie.h"
#include "Comedy.h"
#include "Drama.h"
#include "Classic.h"
#include "HashTable.h"

const int SIZE = 3;

class Blockbuster {
public:
    Blockbuster();
    ~Blockbuster();
    void execute();

private:
    InputProcessor input;
    std::set<Movie*> movies[SIZE];
    HashTable<Customer> customers;
};


#endif //HW5_BLOCKBUSTER_H
