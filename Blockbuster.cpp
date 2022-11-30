//
// Created by USER on 11/23/2022.
//

#include "Blockbuster.h"

Blockbuster::Blockbuster() {

}

Blockbuster::~Blockbuster() {
    for (int i = 0; i < SIZE; i++) {
        std::set<Movie*>::iterator it = movies[i].begin();

        for (; it != movies[i].end(); it++) {
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
