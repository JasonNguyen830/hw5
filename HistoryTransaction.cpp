//
// Created by USER on 11/30/2022.
//

#include "HistoryTransaction.h"

HistoryTransaction::HistoryTransaction() = default;

void HistoryTransaction::execute() {
    displayCustomerHistory();
}

void HistoryTransaction::setCustomer(Customer &customer) {
    this->cust = &customer;
}

void HistoryTransaction::displayCustomerHistory() {
    std::cout << *cust << std::endl;
}
