// Jason Nguyen + Thaddeus Gonzalez-Serna
// HW 5

#ifndef HW5_INPUTPROCESSOR_H
#define HW5_INPUTPROCESSOR_H
// Valid command values
const char B = 'B';
const char R = 'R';
const char H = 'H';
const char I = 'I';

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "MovieFactory.h"
#include "Movie.h"
#include "Customer.h"
#include "HashTable.h"
#include "Transaction.h"
#include "InventoryTransaction.h"
#include "TransactionFactory.h"

class InputProcessor {
public:
    enum MOVIES { COMEDY_ENUM, CLASSICS_ENUM, DRAMA_ENUM, END};
    InputProcessor(); // Constructor
    ~InputProcessor() = default; // Deconstructor

    // Process movies
    void processMovies(std::set<Movie*> movies[]);

    // Process customers
    void processCustomers(HashTable<Customer>&);

    // Process commands to execute
    void processCommands(std::set<Movie*> movies[], HashTable<Customer>&);

private:
    //Helper functions to get values for classic movies
    std::string getDate(std::string input);
    std::string getActor(std::string input);
};


#endif //HW5_INPUTPROCESSOR_H
