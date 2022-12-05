// Jason Nguyen + Thaddeus Gonzalez-Serna
// HW 5

#include "HistoryTransaction.h"

// Constructor
HistoryTransaction::HistoryTransaction() {

}

// Deconstructor
HistoryTransaction::~HistoryTransaction() {

}

// Displays the customer history
void HistoryTransaction::execute() {
    displayCustomerHistory();
}

// Sets the customer
void HistoryTransaction::setCustomer(Customer &customer) {
    this->cust = &customer;
}

// Displays the customer history
void HistoryTransaction::displayCustomerHistory() {
    std::cout << *cust << std::endl;
}
