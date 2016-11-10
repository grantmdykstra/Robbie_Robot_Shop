#include "robot_torso.h"



void RobotTorso::connectLocomotor(RobotLocomotor locomotor) {
        this_robot_locomotor = &locomotor;
}

void RobotTorso::connectArm(RobotArm arm) {

        if (current_arms < 2) {
            this_robot_arm.push_back(arm);
            current_arms++;
        }
}

void RobotTorso::connectBattery(RobotBattery battery) {
    
    if (batteryCompartments < 3) {
        this_robot_battery.push_back(battery);
        batteryCompartments++;
    }

}

void RobotTorso::connectHead(RobotHead head) {
    this_robot_head = &head;
}


