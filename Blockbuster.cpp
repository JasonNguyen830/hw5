//
// Created by USER on 11/23/2022.
//

#include "Blockbuster.h"

Blockbuster::Blockbuster() = default;

Blockbuster::~Blockbuster() {
    for (auto & movie : movies) {
       auto it = movie.begin();

        for (; it != movie.end(); it++) {
            Movie* del = *it;
            delete del;
        }
    }
}

void Blockbuster::execute() {
    input.processMovies(movies);
    input.processCustomers(customers);
    input.processCommands(movies, customers);
}
