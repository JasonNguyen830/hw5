//
// Created by USER on 11/28/2022.
//

#ifndef HW5_CUSTOMER_H
#define HW5_CUSTOMER_H
#include <string>
#include <iostream>
#include <vector>

const int ID_SIZE = 4;

class Customer {
    friend std::ostream& operator<<(std::ostream& ostream, const Customer& customer);

public:
    Customer();
    ~Customer();
    Customer(std::string first, std::string second, const std::string & id);

    bool setCustomerID(const std::string & id);
    bool setFirstName(std::string first);
    bool setLastName(std::string last);
    bool setCustomer(std::string first, std::string last, const std::string & id);

    std::string getID() const;
    std::string getFirstName() const;
    std::string getLastName() const;

    int hash() const;

    void updateHistory(const std::string & history);
private:
    std::string fName;
    std::string lName;
    std::string customerID;
    std::vector<std::string> historyLog;
};


#endif //HW5_CUSTOMER_H
