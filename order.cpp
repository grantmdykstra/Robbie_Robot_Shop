#include "order.h"



void Order::addRobotModel(RobotModel robotModel) {
    robotModels.push_back(robotModel);
}

void Order::addRobotPart(RobotPart robotPart) {
    robotParts.push_back(robotPart);
}

void Order::robotPrice() {
    int i;
    for (i = 0; i < robotModels.size(); i++) {
        this_totalPrice += robotModels[i].getPrice();
    }

    for (i = 0; i < robotParts.size(); i++) {
        this_totalPrice += robotParts[i].getCost();
    }
}



double Order::totalPrice() {
    return this_totalPrice;
}


