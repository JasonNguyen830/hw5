//
// Created by USER on 11/28/2022.
//

#include "Customer.h"

#include <utility>

std::ostream &operator<<(std::ostream &ostream, const Customer &customer) {
    ostream << "\tCustomer Name [" << customer.getFirstName() << " ";
    ostream << customer.getLastName() << "]";
    ostream << "\tID [" << customer.getID() << "] " << std::endl;
    for (const auto & i : customer.historyLog /*int i = 0; i < customer.historyLog.size(); i ++ */) {
        ostream << "\t   " << i << std::endl;
    }

    return ostream;
}

Customer::Customer() {
    setFirstName("");
    setLastName("");
    setCustomerID("");
}

Customer::~Customer() = default;

Customer::Customer(std::string first, std::string second, const std::string & id) {
    setFirstName(std::move(first));
    setLastName(std::move(second));
    setCustomerID(std::move(id));
}

bool Customer::setCustomerID(const std::string & id) {
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

bool Customer::setCustomer(std::string first, std::string last, const std::string & id) {
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

//[implement thad HASH]
int Customer::hash() const {
    std::string str = customerID;
    int ret_val = 0;
    for (int i = 0 ; i < str.size(); i++ ) {
        ret_val += str[i];
    }
    return ret_val;
}

void Customer::updateHistory(const std::string & history) {
    historyLog.push_back(history);
}
