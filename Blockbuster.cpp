// Jason Nguyen + Thaddeus Gonzalez-Serna
// HW 5

#include "Blockbuster.h"

// Constructor
Blockbuster::Blockbuster() = default;

// Deconstructor
Blockbuster::~Blockbuster() {
    for (auto const & movie : movies /*int i = 0; i < SIZE; i++*/) {
        auto it = movie.begin();

        for (; it != movie.end(); it++) {
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
