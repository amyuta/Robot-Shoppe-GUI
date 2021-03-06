#ifndef Arm_h
#define Arm_h

//#include "std_lib_facilities.h"
#include "RobotPart.h"
#include "robot_model.h"



class Arm :public RobotPart {
public:
	Arm(string part_num, double weight, double cost, string description, int power, int quantity) : RobotPart(part_num, weight, cost, description, quantity), p_power(power) {}

	virtual void save_all();
	virtual void save_as_all(string filename);



protected:
	int p_power;
	int power_cons;

};
#endif /* Arm_h */
