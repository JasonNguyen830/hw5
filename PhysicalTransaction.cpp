// Jason Nguyen + Thaddeus Gonzalez-Serna
// HW 5

#include "PhysicalTransaction.h"

// Constructor
PhysicalTransaction::PhysicalTransaction() {
    borrowed = false;
    movie = nullptr;
    customer = nullptr;
}

// Deconstructor
PhysicalTransaction::~PhysicalTransaction() {

}

// Sets the customer
void PhysicalTransaction::setCustomer(Customer &cust) {
    *customer = cust;
}

// Checks the media, type and performs respective actions
// dependent on the validity and typing
void PhysicalTransaction::setStream(std::istream &istream, bool &success) {
    std::string media, type, title, year;
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

        std::set<Movie*>::iterator it = movieTreeReference[0].begin();

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
        std::string day, year, fName, lName, input;
        Movie* classic = new Classic;
        getline(istream, input);
        std::stringstream  str(input);
        str >> day;
        str >> year;
        str >> fName;
        str >> lName;
        std::string fullName = fName + " " + lName;
        classic->setActor(fullName);
        std::string releaseDate = day + " " + year;
        classic->setReleaseDate(releaseDate);

        std::set<Movie*>::iterator it = movieTreeReference[1].begin();

        for(; it != movieTreeReference[1].end(); it++) {
            Movie* check = *it;
            if (classic->getYear() == check->getYear()) {
                this->movie = check;
                break;
            }
        }
        delete classic;
    } else if (type[0] == 'D') {
        std::string director, title;
        Movie* drama = new Drama;
        getline(istream, director, ',');
        istream.get();
        getline(istream, title, ',');
        drama->setDirector(director);
        drama->setTitle(title);

        std::set<Movie*>::iterator it = movieTreeReference[2].begin();
        for(; it != movieTreeReference[2].end(); it++) {
            Movie* check = *it;
            if (*drama == *check) {
                this->movie = check;
                break;
            }
        }
        delete drama;
    } else {
        std::cout << type[0] << " is not a valid movie type" << std::endl;
        success = false;
    }
}
