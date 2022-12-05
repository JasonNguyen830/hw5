//
// Created by USER on 11/30/2022.
//

#ifndef HW5_BORROWTRANSACTION_H
#define HW5_BORROWTRANSACTION_H
#include "Movie.h"
#include "Comedy.h"
#include "Classic.h"
#include "Drama.h"
#include "PhysicalTransaction.h"
#include <iostream>

class BorrowTransaction : public PhysicalTransaction {
public:
    BorrowTransaction();
    ~BorrowTransaction() = default;
    virtual void execute();
    bool borrow(Movie& movie);
    static bool borrowClassic(Movie& movie);
    std::string getLogOfTrans() const;
};


#endif //HW5_BORROWTRANSACTION_H
