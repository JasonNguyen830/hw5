// Jason Nguyen + Thaddeus Gonzalez-Serna
// HW 5

#include "TransactionFactory.h"

// Constructor
TransactionFactory::TransactionFactory() {

}

// Deconstructor
TransactionFactory::~TransactionFactory() {

}

// Creates and sets up a transaction while attributing it to the respective customer and movie.
Transaction *TransactionFactory::createTransaction(std::istream &istream, std::set<Movie *> movies[],
                                                   HashTable<Customer> &customers) {
    std::string type, title, year;
    bool valid = true;

    Transaction* retVal = nullptr;
    HistoryTransaction* history = nullptr;
    BorrowTransaction* borrow = nullptr;
    ReturnTransaction* returnTrans = nullptr;

    Customer cust;
    std::string customerID;

    istream >> type;

    switch(type[0]) {
        case BORROW:
            retVal = new BorrowTransaction;
            retVal->setMovie(movies);
            borrow = dynamic_cast<BorrowTransaction*>(retVal);
            istream >> customerID;
            cust.setCustomerID(customerID);
            borrow->setStream(istream,valid);
            if (valid) {
                if (customers.get(&cust) != nullptr) {
                    customers.get(&cust)->updateHistory(borrow->getLogOfTrans());
                }
            }
            break;
        case RETURN:
            retVal = new ReturnTransaction;
            retVal->setMovie(movies);
            returnTrans = dynamic_cast<ReturnTransaction*>(retVal);
            istream >>customerID;
            cust.setCustomerID(customerID);
            returnTrans->setStream(istream, valid);

            if (valid) {
                if (customers.get(&cust) != nullptr) {
                    customers.get(&cust)->updateHistory(returnTrans->getLogOfTrans());
                }
            }
            break;
        case HISTORY:
            retVal = new HistoryTransaction;
            history = dynamic_cast<HistoryTransaction*>(retVal);

            istream >> customerID;
            cust.setCustomerID(customerID);
            history->setCustomer(*customers.get(&cust));
            break;
        case INVENTORY:
            retVal = new InventoryTransaction;
            retVal->setMovie(movies);
            break;
        default:
            retVal = nullptr;
            std::cout << type[0] << " is an invalid transaction command" << std::endl;
            break;

    }
    return retVal;
}
