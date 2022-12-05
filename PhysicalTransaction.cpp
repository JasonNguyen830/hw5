//
// Created by USER on 11/28/2022.
//

#include "PhysicalTransaction.h"

PhysicalTransaction::PhysicalTransaction() {
    borrowed = false;
    movie = nullptr;
    customer = nullptr;
}


void PhysicalTransaction::setCustomer(Customer &cust) {
    *customer = cust;
}

void PhysicalTransaction::setStream(std::istream &istream, bool &success) {
    std::string media;
    std::string type; 
    std::string title;
    std::string year;
    istream >> media >> type; //double check
    istream.get();

    if (media[0] != 'D') {
        std::cout << "Invalid media. Available: DVD's (D)" << std::endl;
        success = false;
        return;
    }

    if (type[0] =='F') {
        Movie* comedy = new Comedy;
        std::getline(istream, title, ','); // Reads line and stops at comma
        istream >> year;
        comedy->setTitle(title);
        comedy->setYear(year);

       auto /* std::set<Movie*>::iterator */ it = movieTreeReference[0].begin();

        for(; it != movieTreeReference[0].end(); it++) {
            Comedy one = *dynamic_cast<Comedy*>(*it);
            Comedy two = *dynamic_cast<Comedy*>(comedy);

            if (one.getTitle() == two.getTitle() && one.getYear() == two.getYear()) {
                this->movie = *it;
                break;
            }
        }
        delete comedy;
    } else if (type[0] == 'C') {
        std::string day;
        std::string year;
        std::string f_name;
        std::string l_name;
        std::string input;
        Movie* classic = new Classic;
        getline(istream, input);
        std::stringstream  str(input);

        str >> day;
        str >> year;
        str >> f_name;
        str >> l_name;
        std::string combine = f_name + " " + l_name + " " + day + " " + year;
        classic->setYear(combine);

        auto it = movieTreeReference[1].begin();

        for(; it != movieTreeReference[1].end(); it++) {
            Movie* check = *it;
            if (classic->getYear() == check->getYear()) {
                this->movie = check;
                break;
            }
        }
        delete classic;
    } else if (type[0] == 'D') {
        std::string director;
        std::string title;
        Movie* drama = new Drama;
        getline(istream, director, ',');
        istream.get();
        getline(istream, title, ',');
        drama->setDirector(director);
        drama->setTitle(title);

        auto it = movieTreeReference[2].begin();
        for(; it != movieTreeReference[2].end(); it++) {
            Movie* check = *it;
            if (*drama == *check) {
                this->movie = check;
                break;
            }
        }
        delete drama;
    } else {
        std::cout << type[0] << "is not a valid movie type" << std::endl;
        success = false;
    }
}
