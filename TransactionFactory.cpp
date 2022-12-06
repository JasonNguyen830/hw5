// Jason Nguyen + Thaddeus Gonzalez-Serna
// HW 5

#include "TransactionFactory.h"

// Constructor
TransactionFactory::TransactionFactory() = default;

// Creates and sets up a transaction while attributing it to the respective customer and movie.
Transaction *TransactionFactory::createTransaction(std::istream &istream, std::set<Movie *> movies[],
                                                   HashTable<Customer> &customers) {
    std::string type;
    std::string title;
    std::string year;

    bool valid = true;

    Transaction* ret_val = nullptr;
    HistoryTransaction* history = nullptr;
    BorrowTransaction* borrow = nullptr;
    ReturnTransaction* return_trans = nullptr;

    Customer cust;
    std::string customer_id;

    istream >> type;

    switch(type[0]) {
        case BORROW:
            ret_val = new BorrowTransaction;
            ret_val->setMovie(movies);
            borrow = dynamic_cast<BorrowTransaction*>(ret_val);
            istream >> customer_id;
            cust.setCustomerID(customer_id);
            borrow->setStream(istream,valid);
            if (valid) {
                if (customers.get(&cust) != nullptr) {

                    auto log = borrow->getLogOfTrans();
                    
                    customers.get(&cust)->updateHistory(log) ;
                }
            }
            break;
        case RETURN:
            ret_val = new ReturnTransaction;
            ret_val->setMovie(movies);
            return_trans = dynamic_cast<ReturnTransaction*>(ret_val);
            istream >>customer_id;
            cust.setCustomerID(customer_id);
            return_trans->setStream(istream, valid);

            if (valid) {
                if (customers.get(&cust) != nullptr) {

                    auto log = return_trans->getLogOfTrans();
                    customers.get(&cust)->updateHistory(log);
                }
            }
            break;
        case HISTORY:
            ret_val = new HistoryTransaction;
            history = dynamic_cast<HistoryTransaction*>(ret_val);

            istream >> customer_id;
            cust.setCustomerID(customer_id);
            history->setCustomer(*customers.get(&cust));
            break;
        case INVENTORY:
            ret_val = new InventoryTransaction;
            ret_val->setMovie(movies);
            break;
        default:
            ret_val = nullptr;
            std::cout << type[0] << " is an invalid transaction command" << std::endl;
            break;

    }
    return ret_val;
}
