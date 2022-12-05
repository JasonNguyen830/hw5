// Jason Nguyen + Thaddeus Gonzalez-Serna
// HW 5

#ifndef HW5_CUSTOMER_H
#define HW5_CUSTOMER_H
#include <string>
#include <iostream>
#include <vector>

const int ID_SIZE = 4; // Max size of customer ID (Ex. 9999 valid but 10000 not)

class Customer {
    // Outputs customer information
    friend std::ostream& operator<<(std::ostream& ostream, const Customer& customer);

public:
    Customer(); // Constructor
    ~Customer(); // Deconstructor
    //Constructor
    Customer(std::string first, std::string second, std::string id);

    // Setter functions
    bool setCustomerID(std::string id);
    bool setFirstName(std::string first);
    bool setLastName(std::string last);
    bool setCustomer(std::string first, std::string last, std::string id);

    // Getter functions
    std::string getID() const;
    std::string getFirstName() const;
    std::string getLastName() const;

    // Hash
    int hash() const;

    // Updates history log
    void updateHistory(std::string history);
private:
    std::string fName; // First Name
    std::string lName; // Last Name
    std::string customerID; // ID
    std::vector<std::string> historyLog; // History Log
};


#endif //HW5_CUSTOMER_H
