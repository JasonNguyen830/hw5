// Jason Nguyen + Thaddeus Gonzalez-Serna
// HW 5

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
    BorrowTransaction(); // Constructor
    ~BorrowTransaction(); // Deconstructor
    void execute(); // Executes the borrow action
    bool borrow(Movie& movie); // Borrows a movie
    bool borrowClassic(Movie& movie); // Borrows classic movies
    std::string getLogOfTrans() const; // Gets transaction log
};


#endif //HW5_BORROWTRANSACTION_H
