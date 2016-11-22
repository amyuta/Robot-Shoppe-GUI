#ifndef ROBOT_MODEL_H
#define ROBOT_MODEL_H
//#include "std_lib_facilities.h"
#include "RobotPart.h"
#include<string>


class Robot_Model {
    friend RobotPart;
public:
    Robot_Model(string r_name, string r_num, string image, double r_price)
        : name(r_name), model_num(r_num), image(image), price(r_price) {}
    
    void make_robotmodel(RobotPart head, RobotPart arm, RobotPart battery, RobotPart loco, RobotPart torso);
    void show_model();
	string list_model();
	string get_image();
    double get_price();
    virtual void save_alls();
	virtual void save_as_alls(string filename);
	int get_modNum();
    

protected:
    string name;
    string model_num;
	string image;
    double price;
    vector<RobotPart> parts;
};
#endif // ROBOT_MODEL_H
