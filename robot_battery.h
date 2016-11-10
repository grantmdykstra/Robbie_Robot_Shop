#ifndef __ROBOT_BATTERY
#define __ROBOT_BATTERY 2016
#include "robot_part.h"



class RobotBattery : public RobotPart {

    private:
        double this_energy;
        double this_maxPower;

    public:
        RobotBattery(std::string name, int partNum, double weight, double cost, std::string description, double energy, double maxPower)
            : RobotPart(name, partNum, weight, cost, description, 4), this_energy(energy), this_maxPower(maxPower) { }

        double getEnergy() {return this_energy;}
        double getMaxPower() {return this_maxPower;}
        

};

#endif