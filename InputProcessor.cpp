//
// Created by USER on 11/23/2022.
//

#include "InputProcessor.h"

InputProcessor::InputProcessor() {

}

InputProcessor::~InputProcessor() {

}

void InputProcessor::processMovies(std::set<Movie *> movies[]) {
    std::fstream input;
    input.open("data4movies.txt");
    while (!input.eof()) {
        std::string readInput;
        std::getline(input, readInput);
        std::stringstream lineInput(readInput);
        getline(lineInput, readInput, ',');
        char type = readInput[0];

        Movie* temp = MovieFactory::createMovie(type);

        if (temp) {
            getline(lineInput, readInput, ',');
            int stock = atoi(readInput.c_str());

            temp->setStock(stock);
            lineInput.get();
            getline(lineInput, readInput, ',');
            std::string director = readInput;

            temp->setDirector(director);

            lineInput.get();
            getline(lineInput, readInput, ',');
            std::string title = readInput;

            temp->setTitle(title);

            lineInput.get();
            getline(lineInput, readInput, ',');
            std::string year = readInput;

            year.resize(year.size() - 1);

            temp->setYear(year);

            std::set<Movie*>::iterator it;
            Movie* tempMovieComparator;
            switch (temp->getChar()) {
                case COMEDY:
                    movies[COMEDY_ENUM].insert(temp);
                    break;
                case CLASSIC:
                    it = movies[CLASSICS_ENUM].begin();
                    for (; it != movies[CLASSICS_ENUM].end(); it++) {
                        tempMovieComparator = *it;
                        if (*temp == *tempMovieComparator){
                            temp->setOtherMovie(tempMovieComparator);
                            tempMovieComparator->setOtherMovie(temp);
                        }
                    }

                    movies[CLASSICS_ENUM].insert(temp);
                    break;
                case DRAMA:
                    movies[DRAMA_ENUM].insert(temp);
                    break;
                default:
                    break;
            }
        }

    }
    input.close();
}

void InputProcessor::processCustomers(HashTable<Customer> &customerContainer) {
    std::fstream input;
    input.open("data4customers.txt");
    Customer* customer;
    while (!input.eof()) {
        std::string ID, lName, fName;
        input >> ID;
        input >> lName;
        input >> fName;
        customer = new Customer(fName, lName, ID);
        customerContainer.insert(customer);
    }
    input.close();
}

void InputProcessor::processCommands(std::set<Movie *> movies[], HashTable<Customer> &customers) {
    if (movies == nullptr) {
        return;
    }

    std::fstream input;
    input.open("data4commands.txt");
    std::string readInput;

    while (!input.eof()) {
        getline(input, readInput);
        std::stringstream lineInput(readInput);

        Transaction* transaction = TransactionFactory::createTransaction(lineInput, movies, customers);
        if (transaction) {
            transaction->execute();
        }
        delete transaction;
    }
    input.close();
}
