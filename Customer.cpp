//
// Created by USER on 11/28/2022.
//

#include "Customer.h"

#include <utility>

std::ostream &operator<<(std::ostream &ostream, const Customer &customer) {
    ostream << "\tCustomer Name [" << customer.getFirstName() << " ";
    ostream << customer.getLastName() << "]";
    ostream << "\tID [" << customer.getID() << "] " << std::endl;
    for (int i = 0; i < customer.historyLog.size(); i ++) {
        ostream << "\t   " << customer.historyLog[i] << std::endl;
    }

    return ostream;
}

Customer::Customer() {
    setFirstName("");
    setLastName("");
    setCustomerID("");
}

Customer::~Customer() = default;

Customer::Customer(std::string first, std::string second, std::string id) {
    setFirstName(std::move(first));
    setLastName(std::move(second));
    setCustomerID(std::move(id));
}

bool Customer::setCustomerID(std::string id) {
    if (id.length() == ID_SIZE) {
        customerID = id;
        return true;
    } else {
        return false;
    }
}

bool Customer::setFirstName(std::string first) {
    fName = std::move(first);
    return true;
}

bool Customer::setLastName(std::string last) {
    lName = std::move(last);
    return true;
}

bool Customer::setCustomer(std::string first, std::string last, std::string id) {
    return setFirstName(std::move(first)) &&
    setLastName(std::move(last)) &&
    setCustomerID(std::move(id));
}

std::string Customer::getID() const {
    return customerID;
}

std::string Customer::getFirstName() const {
    return fName;
}

std::string Customer::getLastName() const {
    return lName;
}

int Customer::hash() const {
    std::string str = customerID;
    int retVal = 0;
    for (int i = 0; i < str.size(); i++) {
        retVal += str[i];
    }
    return retVal;
}

void Customer::updateHistory(std::string history) {
    historyLog.push_back(history);
}
