// Jason Nguyen + Thaddeus Gonzalez-Serna
// HW 5

#include "Customer.h"

#include <utility>

// Prints the customer information and log
std::ostream &operator<<(std::ostream &ostream, const Customer &customer) {
    ostream << "\tCustomer Name [" << customer.getFirstName() << " ";
    ostream << customer.getLastName() << "]";
    ostream << "\tID [" << customer.getID() << "] " << std::endl;
    for (int i = 0; i < customer.historyLog.size(); i ++) {
        ostream << "\t   " << customer.historyLog[i] << std::endl;
    }

    return ostream;
}

// Constructor
Customer::Customer() {
    setFirstName("");
    setLastName("");
    setCustomerID("");
}

// Deconstructor
Customer::~Customer() = default;

// Constructor
Customer::Customer(std::string first, std::string second, std::string id) {
    setFirstName(std::move(first));
    setLastName(std::move(second));
    setCustomerID(std::move(id));
}

// Sets the customer id and returns true if the size is 4 or less
bool Customer::setCustomerID(std::string id) {
    if (id.length() == ID_SIZE) {
        customerID = id;
        return true;
    } else {
        return false;
    }
}

// Sets the first name of the customer
bool Customer::setFirstName(std::string first) {
    fName = std::move(first);
    return true;
}

// Sets the last name of the customer
bool Customer::setLastName(std::string last) {
    lName = std::move(last);
    return true;
}

// Set the customer attributes
bool Customer::setCustomer(std::string first, std::string last, std::string id) {
    return setFirstName(std::move(first)) &&
    setLastName(std::move(last)) &&
    setCustomerID(std::move(id));
}

// Returns customer ID
std::string Customer::getID() const {
    return customerID;
}

// Returns customer first name
std::string Customer::getFirstName() const {
    return fName;
}

// Returns customer last name
std::string Customer::getLastName() const {
    return lName;
}

// Hash method for customer
int Customer::hash() const {
    std::string str = customerID;
    int retVal = 0;
    for (int i = 0; i < str.size(); i++) {
        retVal += str[i];
    }
    return retVal;
}

// Updates history log for customers
void Customer::updateHistory(std::string history) {
    historyLog.push_back(history);
}
