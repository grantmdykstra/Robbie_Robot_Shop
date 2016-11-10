#ifndef __ROBOT_ARM
#define __ROBOT_ARM 2016
#include <string>
#include "robot_part.h"

class RobotArm : public RobotPart {
    public:
        RobotArm(std::string name, int partNum, double weight, double cost, std::string description)
            : RobotPart(name, partNum, weight, cost, description, 2) { }
            
        int powerConsumed(int speed);
};

#endif

