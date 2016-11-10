#include "robot_part.h"


std::string RobotPart::getName() {
	return this_name;
}

int RobotPart::getPartNumber() {
	return this_partNumber;
}

int RobotPart::getPartType() {					//0=head; 1=chest; 2=arm; 3=locomotor; 4=battery
	return this_partType;
}

double RobotPart::getWeight() {
	return this_weight;
}

double RobotPart::getCost() {
	return this_cost;
}

std::string RobotPart::getDescription() {
	return this_description;
}
