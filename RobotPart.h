#ifndef __ROBOTPART_H
#define __ROBOTPART_H 

#include <vector>
#include <string>


using namespace std;

class RobotPart {
	
protected:
    string p_num;
    double p_weight;
    double p_cost;
    string p_description;
    int p_quantity;
    
public:
    RobotPart(string part_num, double weight, double cost, string description, int quantity) : p_num(part_num), p_weight(weight), p_cost(cost), p_description(description), p_quantity(quantity) {}
    
    
    void list_all();
   // void add_quan(int part_num, int quantity);
    void list_all_detail();
  //  int get_pnum();
    double get_cost();
	string get_info(string allDetails);
    
    virtual int quan_count();
    virtual void save_all();
	virtual void save_as_all(string filename);


};
#endif
