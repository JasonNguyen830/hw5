//
// Created by USER on 11/30/2022.
//

#ifndef HW5_HISTORYTRANSACTION_H
#define HW5_HISTORYTRANSACTION_H
#include "DisplayTransaction.h"
#include "Customer.h"
#include "HashTable.h"

class HistoryTransaction : public DisplayTransaction {
public:
    HistoryTransaction();
    ~HistoryTransaction() = default;
    virtual void execute();
    void setCustomer(Customer&);
    void displayCustomerHistory();
private:
    Customer* cust;
};


#endif //HW5_HISTORYTRANSACTION_H
