// Jason Nguyen + Thaddeus Gonzalez-Serna
// HW 5

#ifndef HW5_HISTORYTRANSACTION_H
#define HW5_HISTORYTRANSACTION_H
#include "DisplayTransaction.h"
#include "Customer.h"
#include "HashTable.h"

class HistoryTransaction : public DisplayTransaction {
public:
    HistoryTransaction(); // Constructor
    ~HistoryTransaction() = default; // Deconstructor
    void execute();
    void setCustomer(Customer&); // Sets the customer
    void displayCustomerHistory(); // Displays the customer history
private:
    Customer* cust; // Customer object
};


#endif //HW5_HISTORYTRANSACTION_H
