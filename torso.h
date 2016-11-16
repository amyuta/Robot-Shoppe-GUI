#ifndef TORSO_H
#define TORSO_H

//#include "std_lib_facilities.h"
#include "shoppe.h"
#include "RobotPart.h"
#include "robot_model.h"

using namespace std;

class Torso:public RobotPart {
    protected:
    int p_battcount;
    

    public:
     Torso(int part_num, double weight, double cost, string description, int batt_count, int quantity) : p_battcount(batt_count), RobotPart(part_num, weight, cost, description, quantity){}

    virtual int quan_count();
    
    virtual void save_all();
    
    

 };
 #endif


