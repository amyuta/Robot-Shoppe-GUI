
#ifndef Locomotor_h
#define Locomotor_h
#include "string"
//#include "std_lib_facilities.h"
#include "RobotPart.h"
#include "robot_model.h"

class Locomotor:public RobotPart {
      
public:
    Locomotor(int part_num, double weight, double cost, string description, int power, int max_speed, int quantity) : p_power(power), p_maxspeed(max_speed), RobotPart(part_num, weight, cost, description, quantity){}

   virtual void save_all(); 
    double find_maxspeed();
    double find_powerconsumed();
    //need to create a .cpp file
    
protected:
    int loco_count;
    int p_power;
    int p_maxspeed;
    //might need to create more variables for max speed& power consumed
    
    
};




#endif /* Locomotor_h */
