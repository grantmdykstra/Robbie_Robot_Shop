#ifndef __ROBOT_MODEL
#define __ROBOT_MODEL 2016

#include <iostream>
#include <string>
#include <vector>
#include "robot_part.h"
#include "robot_head.h"
#include "robot_torso.h"
#include "robot_arm.h"
#include "robot_locomotor.h"
#include "robot_battery.h"

using namespace std;
using std::string;

class RobotModel {
	private:
		string this_name;
		int this_modelNumber;
		int this_numberOfPieces;
		int this_maxSpeed;
		double this_price;
		vector<RobotPart> this_robotParts;


	public:
		RobotModel(string name, int modelNumber)
			: this_name(name), this_modelNumber(modelNumber), this_numberOfPieces(0), this_maxSpeed(0), this_price(0) {}
		string getName();
		int getModelNumber();
		double getPrice();
		double getComponentCost(RobotPart);
		double getMaxSpeed();
		void addPart(RobotHead);
		void addPart(RobotTorso);
		void addPart(RobotArm);
		void addPart(RobotLocomotor);
		void addPart(RobotBattery);
		
};

#endif