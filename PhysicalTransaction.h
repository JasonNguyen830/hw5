// Jason Nguyen + Thaddeus Gonzalez-Serna
// HW 5

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
    PhysicalTransaction(); // Constructor
    ~PhysicalTransaction() = default; // Deconstructor
    virtual void execute() = 0; // Execute property
    void setCustomer(Customer& cust); // Sets customer
    // Checks the media, type and performs respective actions
    // dependent on the validity and typing
    void setStream(std::istream& istream, bool& success);
    virtual std::string getLogOfTrans() const = 0; // Log of transactions

protected:
    Movie* movie; // Movie object
    Customer* customer; // Customer
    bool borrowed; // True if movie is borrowed
};


#endif //HW5_PHYSICALTRANSACTION_H
