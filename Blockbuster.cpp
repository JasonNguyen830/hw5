// Jason Nguyen + Thaddeus Gonzalez-Serna
// HW 5

#include "Blockbuster.h"

// Constructor
Blockbuster::Blockbuster() {

}

// Deconstructor
Blockbuster::~Blockbuster() {
    for (int i = 0; i < SIZE; i++) {
        std::set<Movie*>::iterator it = movies[i].begin();

        for (; it != movies[i].end(); it++) {
            Movie* del = *it;
            delete del;
        }
    }
}

// Reads and process movies, customers, and commands
void Blockbuster::execute() {
    input.processMovies(movies);
    input.processCustomers(customers);
    input.processCommands(movies, customers);
}
