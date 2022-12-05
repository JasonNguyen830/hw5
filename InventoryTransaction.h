//
// Created by USER on 11/30/2022.
//

#ifndef HW5_INVENTORYTRANSACTION_H
#define HW5_INVENTORYTRANSACTION_H
#include "Movie.h"
#include "DisplayTransaction.h"
#include <iostream>
#include <set>
#include <algorithm>

const std::string MOVIE_TYPE[] = { "Comedy", "Classic", "Drama"};

class InventoryTransaction : public DisplayTransaction {
public:
    InventoryTransaction();
    ~InventoryTransaction() = default;
    virtual void execute();
    void displayInventory(std::set<Movie*> movies[], int size);
};


#endif //HW5_INVENTORYTRANSACTION_H
