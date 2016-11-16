#include "RobotPart.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <ostream>
#include <fstream>


using namespace std;


void RobotPart:: list_all(){

    cout << p_num << endl;
    
}

void RobotPart:: add_quan(int part_num, int quantity){
    
    if(p_num == part_num){
        p_quantity = p_quantity + quantity;
    }
}

void RobotPart:: list_all_detail() {
    cout << "hello";
}

double RobotPart::get_cost() {
    
    return p_cost;
    
}

int RobotPart::get_pnum() {
    return p_num;
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


