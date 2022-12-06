// Jason Nguyen + Thaddeus Gonzalez-Serna
// HW 5

#ifndef HW5_DISPLAYTRANSACTION_H
#define HW5_DISPLAYTRANSACTION_H
#include "Transaction.h"

class DisplayTransaction : public Transaction {
public:
    DisplayTransaction(); // Constructor
    ~DisplayTransaction() = default; // Deconstructor
    virtual void execute() = 0;
};


#endif //HW5_DISPLAYTRANSACTION_H
