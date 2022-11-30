//
// Created by USER on 11/28/2022.
//

#ifndef HW5_PHYSICALTRANSACTION_H
#define HW5_PHYSICALTRANSACTION_H
#include "Transaction.h"
#include "Customer.h"
#include "Movie.h"
#include "Comedy.h"
#include "Drama.h"
#include "Classic.h"
#include <iostream>

class PhysicalTransaction : public Transaction {
public:
    PhysicalTransaction();
    ~PhysicalTransaction();
    virtual void execute() = 0;
    void setCustomer(Customer& cust);
    void setStream(std::istream& istream, bool& success);
    virtual std::string getLogOfTrans() const = 0;

protected:
    Movie* movie;
    Customer* customer;
    bool borrowed;
};


#endif //HW5_PHYSICALTRANSACTION_H
