//
// Created by USER on 11/28/2022.
//

#ifndef HW5_TRANSACTIONFACTORY_H
#define HW5_TRANSACTIONFACTORY_H
#include <iostream>
#include "Transaction.h"
#include "BorrowTransaction.h"
#include "ReturnTransaction.h"
#include "HistoryTransaction.h"
#include "InventoryTransaction.h"
#include "PhysicalTransaction.h"
#include "DisplayTransaction.h"
#include "HashTable.h"
#include "Customer.h"
const char BORROW = 'B';
const char RETURN = 'R';
const char HISTORY = 'H';
const char INVENTORY = 'I';

class TransactionFactory {
public:
    TransactionFactory();
    ~TransactionFactory();
    static Transaction* createTransaction(std::istream& istream, std::set<Movie*> movies[], HashTable<Customer>& customers);
};


#endif //HW5_TRANSACTIONFACTORY_H
