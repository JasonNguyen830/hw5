// Jason Nguyen + Thaddeus Gonzalez-Serna
// HW 5

#ifndef HW5_INVENTORYTRANSACTION_H
#define HW5_INVENTORYTRANSACTION_H
#include "Movie.h"
#include "DisplayTransaction.h"
#include <iostream>
#include <set>
#include <algorithm>

// Contains 3 unique movie types (can be updated for more movie types)
const std::string MOVIE_TYPE[] = { "Comedy", "Classic", "Drama"};

class InventoryTransaction : public DisplayTransaction {
public:
    InventoryTransaction(); // Constructor
    ~InventoryTransaction(); // Deconstructor
    void execute(); // Executes the display inventory
    // Displays the inventory of movies
    void displayInventory(std::set<Movie*> movies[], int size);
};


#endif //HW5_INVENTORYTRANSACTION_H
