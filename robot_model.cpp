#include <stdio.h>
#include<string>
#include <iostream>
#include <iomanip>
#include <ostream>
#include <fstream>
#include <vector>
#include "robot_model.h"

using namespace std;

void Robot_Model:: make_robotmodel(RobotPart head, RobotPart arm, RobotPart battery, RobotPart loco, RobotPart torso){
    
    parts.push_back(head);
    parts.push_back(arm);
    parts.push_back(battery);
    parts.push_back(loco);
    parts.push_back(torso);

}

void Robot_Model::show_model(){
    
    cout << "Name: " << name << endl << "Model Number: " << model_num << endl;
    
    cout <<"Head: Part Number: ";
    parts[0].list_all();
    cout << "Arm: Part Number: ";
    parts[1].list_all();
    cout << "Battery: Part Number: ";
    parts[2].list_all();
    cout << "Locomotor: Part Number: ";
    parts[3].list_all();
    cout << "Torso: Part Number: ";
    parts[4].list_all();
    
    
}

double Robot_Model::get_price(){
    
    return price;
}

void Robot_Model:: save_alls() {

    ofstream ofs;
    ofs.open("data.txt", ofstream::out | ofstream::app);

        ofs << name << endl;
        ofs << model_num << endl;
        ofs << price << endl;

    ofs.close();

    parts[0].save_all();
    parts[1].save_all();
    parts[2].save_all();
    parts[3].save_all();
    parts[4].save_all();


}

void Robot_Model::save_as_alls(string filename) {

	ofstream ofs;
	ofs.open(filename.c_str(), ofstream::out | ofstream::app);

	ofs << name << endl;
	ofs << model_num << endl;
	ofs << price << endl;

	ofs.close();

	parts[0].save_as_all(filename);
	parts[1].save_as_all(filename);
	parts[2].save_as_all(filename);
	parts[3].save_as_all(filename);
	parts[4].save_as_all(filename);


}
