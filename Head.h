

#ifndef Head_h
#define Head_h

//#include "std_lib_facilities.h"
#include "shoppe.h"
#include "RobotPart.h"

class Head: public RobotPart {
public:
    Head(int part_num, double weight, double cost, string description, int quantity) : RobotPart(part_num, weight, cost, description, quantity){}
    
    

protected:
    int head_count;
    
};
#endif /* Head_h */
