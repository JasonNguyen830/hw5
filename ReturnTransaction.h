//
// Created by USER on 11/28/2022.
//

#ifndef HW5_RETURNTRANSACTION_H
#define HW5_RETURNTRANSACTION_H
#include "Movie.h"
#include "Comedy.h"
#include "Classic.h"
#include "PhysicalTransaction.h"

class ReturnTransaction: public PhysicalTransaction {
public:
    ReturnTransaction();
    ~ReturnTransaction();
    virtual void execute();
    bool executeReturn(Movie& movie);
    std::string getLogOfTrans() const;
};


#endif //HW5_RETURNTRANSACTION_H
