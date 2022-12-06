// Jason Nguyen + Thaddeus Gonzalez-Serna
// HW 5

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

const int SIZE = 3; // Number of types of movies

class Blockbuster {
public:
    Blockbuster(); // Constructor
    ~Blockbuster() ; // Deconstructor
    void execute(); // Reads and process movies, customers, and commands

private:
    InputProcessor input; // Input source
    std::set<Movie*> movies[SIZE]; // Movie collection
    HashTable<Customer> customers; // Hashtable of customers
};


#endif //HW5_BLOCKBUSTER_H
