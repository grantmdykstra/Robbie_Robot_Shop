#ifndef __ROBOT_HEAD
#define __ROBOT_HEAD 2016
#include <string>
#include "robot_part.h"



class RobotHead : public RobotPart {
    public:
        RobotHead(std::string name, int partNum, double weight, double cost, std::string description)
            : RobotPart(name, partNum, weight, cost, description, 0) { }

};

#endif