//
// Created by USER on 11/30/2022.
//

#ifndef HW5_DISPLAYTRANSACTION_H
#define HW5_DISPLAYTRANSACTION_H
#include "Transaction.h"

class DisplayTransaction : public Transaction {
public:
    DisplayTransaction();
    ~DisplayTransaction() = default;
    virtual void execute() = 0;
};


#endif //HW5_DISPLAYTRANSACTION_H
