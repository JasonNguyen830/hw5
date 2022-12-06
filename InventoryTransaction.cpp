// Jason Nguyen + Thaddeus Gonzalez-Serna
// HW 5

#include "InventoryTransaction.h"

// Constructor
InventoryTransaction::InventoryTransaction() = default;

// Executes the inventory
void InventoryTransaction::execute() {
    displayInventory(movieTreeReference, 3);
}

// Displays the inventory
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
