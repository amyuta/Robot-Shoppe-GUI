#ifndef BATTERY_H
#define BATTERY_H

//#include "std_lib_facilities.h"
#include "shoppe.h"
#include "RobotPart.h"
#include "robot_model.h"

using namespace std;

class Battery :public RobotPart {
protected:
	int p_energy;


public:
	Battery(int part_num, double weight, double cost, string description, int energy, int quantity) : p_energy(energy), RobotPart(part_num, weight, cost, description, quantity) {}


	virtual void save_all();
	virtual void save_as_all(string filename);



};
#endif


#pragma once
