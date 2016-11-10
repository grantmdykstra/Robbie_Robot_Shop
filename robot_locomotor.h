#ifndef __ROBOT_LOCOMOTOR
#define __ROBOT_LOCOMOTOR 2016
#include "robot_part.h"
#include <string>


class RobotLocomotor : public RobotPart {
    private:
        int this_maxSpeed;

    public:
        RobotLocomotor(std::string name, int partNum, double weight, double cost, std::string description, int maxSpeed)
            : RobotPart(name, partNum, weight, cost, description, 3), this_maxSpeed(maxSpeed) { }

        int getMaxSpeed() {return this_maxSpeed;}

        int powerConsumed(int speed);
};

#endif