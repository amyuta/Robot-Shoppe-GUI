#include "RobotPart.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <ostream>
#include <fstream>


using namespace std;

string RobotPart::get_info(string allDetails) {



	allDetails ="Part #: "+ p_num + " Description: " + p_description;
	return allDetails;

	
}

void RobotPart:: list_all(){

    cout << p_num << endl;
    
}

void RobotPart:: list_all_detail() {
    cout << "hello";
}

double RobotPart::get_cost() {
    
    return p_cost;
    
}

void RobotPart::save_all() {

    ofstream ofs;
    ofs.open("data.txt", ofstream::out | ofstream::app);

            ofs << p_num << endl;
            ofs << p_weight << endl;
            ofs << p_cost << endl;
            ofs << p_quantity << endl;
            ofs << p_description << endl;

            ofs.close();

}

void RobotPart::save_as_all(string filename) {

	ofstream ofs;
	ofs.open(filename.c_str(), ofstream::out | ofstream::app);

	ofs << p_num << endl;
	ofs << p_weight << endl;
	ofs << p_cost << endl;
	ofs << p_quantity << endl;
	ofs << p_description << endl;

	ofs.close();

}
int RobotPart::quan_count(){
    return p_quantity;
}


