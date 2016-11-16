#ifndef BATTERY_H
#define BATTERY_H

//#include "std_lib_facilities.h"
#include "RobotPart.h"
#include "robot_model.h"

class Battery : public RobotPart {
    protected:
    
    int p_energy;

    public:
     Battery(int part_num, double weight, double cost, string description, int energy, int quantity) : p_energy(energy), RobotPart(part_num, weight, cost, description, quantity){}

	virtual void save_all(); 

 };


#endif // BATTERY_H
