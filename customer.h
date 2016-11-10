#ifndef __ROBOT_CUSTOMER
#define __ROBOT_CUSTOMER 2016

#include <iostream>
#include <vector>
#include <string>

class Customer {
    private:
        std::string name;
        int customerNumber;
        double wallet;

    public:
        Customer(std::string custname, int custNumber, double custwallet)
            : name(custname), customerNumber(custNumber), wallet(custwallet) { }
        std::string getName();
        int getCustomerNumber();
        double getWallet();
        double getRemainingWallet(double money);
        
};

#endif