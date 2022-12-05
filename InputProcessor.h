//
// Created by USER on 11/23/2022.
//

#ifndef HW5_INPUTPROCESSOR_H
#define HW5_INPUTPROCESSOR_H
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
    InputProcessor();
    ~InputProcessor() = default;

    void processMovies(std::set<Movie*> movies[]);

    void processCustomers(HashTable<Customer>&);

    void processCommands(std::set<Movie*> movies[], HashTable<Customer>&);
};


#endif //HW5_INPUTPROCESSOR_H
