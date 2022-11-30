//
// Created by USER on 11/30/2022.
//

#include "InventoryTransaction.h"

InventoryTransaction::InventoryTransaction() {

}

InventoryTransaction::~InventoryTransaction() {

}

void InventoryTransaction::execute() {
    displayInventory(movieTreeReference, 3);
}

void InventoryTransaction::displayInventory(std::set<Movie *> *movies, int size) {
    std::cout << "Inventory: " << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << "_______________________" << std::endl;
        std::cout << MOVIE_TYPE[i] << " " << std::endl;
        std::cout << "_______________________" << std::endl;
        std::set<Movie*>::iterator j = movies[i].begin();
        for (; j != movies[i].end(); j++) {
            std::cout << **j << std::endl;
        }
    }
}
