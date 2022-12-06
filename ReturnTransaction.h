// Jason Nguyen + Thaddeus Gonzalez-Serna
// HW 5

#ifndef HW5_RETURNTRANSACTION_H
#define HW5_RETURNTRANSACTION_H
#include "Movie.h"
#include "Comedy.h"
#include "Classic.h"
#include "PhysicalTransaction.h"

class ReturnTransaction: public PhysicalTransaction {
public:
    ReturnTransaction(); // Constructor
    ~ReturnTransaction() = default; // Deconstructor
    virtual void execute(); // Execution method
    bool executeReturn(Movie& movie); // Executes return policy
    std::string getLogOfTrans() const; // Return transaction log
};


#endif //HW5_RETURNTRANSACTION_H
