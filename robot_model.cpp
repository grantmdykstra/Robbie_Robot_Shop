#include <iostream>
#include <string>
#include "robot_model.h"
#include "robot_part.h"
#include "robot_head.h"
#include "robot_torso.h"
#include "robot_arm.h"
#include "robot_locomotor.h"
#include "robot_battery.h"

string RobotModel::getName() {
    return this_name;
}

int RobotModel::getModelNumber() {
    return this_modelNumber;
}

double RobotModel::getPrice() {
    return this_price;
}

double RobotModel::getComponentCost(RobotPart piece) {
    return piece.getCost();
}

double RobotModel::getMaxSpeed() {
    return this_maxSpeed;
}

void RobotModel::addPart(RobotHead piece) {
    this_robotParts.push_back(piece);
    this_numberOfPieces++;
    this_price=this_price+piece.getCost();
}

void RobotModel::addPart(RobotTorso piece) {
    this_robotParts.push_back(piece);
    this_numberOfPieces++;
    this_price=this_price+piece.getCost();
}

void RobotModel::addPart(RobotArm piece) {
    this_robotParts.push_back(piece);
    this_numberOfPieces++;
    this_price=this_price+piece.getCost();
}

void RobotModel::addPart(RobotLocomotor piece) {
    this_robotParts.push_back(piece);
    this_numberOfPieces++;
    this_price=this_price+piece.getCost();
    this_maxSpeed=this_maxSpeed+piece.getMaxSpeed();
}

void RobotModel::addPart(RobotBattery piece) {
    this_robotParts.push_back(piece);
    this_numberOfPieces++;
    this_price=this_price+piece.getCost();
}
