#ifndef __ROBOT_TORSO
#define __ROBOT_TORSO 2016

#include <iostream>
#include <string>
#include <vector>
#include "robot_part.h"
#include "robot_battery.h"
#include "robot_head.h"
#include "robot_locomotor.h"
#include "robot_arm.h"

class RobotTorso : public RobotPart {

    private:
    
        int batteryCompartments;
        int current_arms = 0;
    

    public:
        std::vector<RobotArm> this_robot_arm;
        RobotHead *this_robot_head;
        std::vector<RobotBattery> this_robot_battery;
        RobotLocomotor *this_robot_locomotor;

        RobotTorso(std::string name, int partNum, double weight, double cost, std::string description, int compartments)
            : RobotPart(name, partNum, weight, cost, description, 1), batteryCompartments(compartments) { }


        int getCompartments() {return batteryCompartments;}


        void connectArm(RobotArm arm);
        void connectLocomotor(RobotLocomotor locomotor);
        void connectBattery(RobotBattery battery);
        void connectHead(RobotHead head);



/*

        void connectLocomotor(RobotLocomotor locomotor) {
        this_robot_locomotor = &locomotor;
        }

        void connectArm(RobotArm arm) {

                if (current_arms < 2) {
                    this_robot_arm.push_back(arm);
                    current_arms++;
                }
        }

        void connectBattery(RobotBattery battery) {
            
            if (batteryCompartments < 3) {
                this_robot_battery.push_back(battery);
                batteryCompartments++;
            }

        }

        void connectHead(RobotHead head) {
            this_robot_head = &head;

        }

*/


};

#endif

