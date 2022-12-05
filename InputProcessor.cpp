//
// Created by USER on 11/23/2022.
//

#include "InputProcessor.h"

InputProcessor::InputProcessor() = default;


void InputProcessor::processMovies(std::set<Movie *> movies[]) {
    std::fstream input;
    input.open("data4movies.txt");
    while (!input.eof()) {
        std::string read_input;
        std::getline(input, read_input);
        std::stringstream line_input(read_input);
        getline(line_input, read_input, ',');
        char type = read_input[0];

        Movie* temp = MovieFactory::createMovie(type);

        if (temp) {
            getline(line_input, read_input, ',');
            int stock = atoi(read_input.c_str());

            temp->setStock(stock);
            line_input.get();
            getline(line_input, read_input, ',');
            std::string director = read_input;

            temp->setDirector(director);

            line_input.get();
            getline(line_input, read_input, ',');
            std::string title = read_input;

            temp->setTitle(title);

            line_input.get();
            getline(line_input, read_input, ',');
            std::string year = read_input;

            year.resize(year.size() - 1);

            temp->setYear(year);

            std::set<Movie*>::iterator it;
            Movie* temp_movie_comparator;
            switch (temp->getChar()) {
                case COMEDY:
                    movies[COMEDY_ENUM].insert(temp);
                    break;
                case CLASSIC:
                    it = movies[CLASSICS_ENUM].begin();
                    for (; it != movies[CLASSICS_ENUM].end(); it++) {
                        temp_movie_comparator = *it;
                        if (*temp == *temp_movie_comparator){
                            temp->setOtherMovie(temp_movie_comparator);
                            temp_movie_comparator->setOtherMovie(temp);
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
        std::string id;
        std::string l_name;
        std::string f_name;
        input >> id;
        input >> l_name;
        input >> f_name;
        customer = new Customer(f_name, l_name, id);
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
    std::string read_input;

    while (!input.eof()) {
        getline(input, read_input);
        std::stringstream line_input(read_input);

        Transaction* transaction = TransactionFactory::createTransaction(line_input, movies, customers);
        if (transaction) {
            transaction->execute();
        }
        delete transaction;
    }
    input.close();
}
