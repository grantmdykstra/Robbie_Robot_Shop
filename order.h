#ifndef __ROBOT_ORDER
#define __ROBOT_ORDER 2016

#include "robot_model.h"
#include "robot_part.h"
#include "customer.h"
#include "sales_associate.h"


class Order {
    private:
        int orderNumber;
        double this_totalPrice = 0;                     

    public:

        SalesAssociate *this_sales;
        Customer *this_customer;
        std::vector<RobotModel> robotModels;
        std::vector<RobotPart> robotParts;

        Order(Customer *customer, SalesAssociate *sales, int number) : this_customer(customer), this_sales(sales), orderNumber(number) { } 
        void addRobotModel(RobotModel robotModel);
        void addRobotPart(RobotPart robotPart);
        void robotPrice();
        double totalPrice();
};

#endif