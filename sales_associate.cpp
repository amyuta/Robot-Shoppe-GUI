#include "sales_associate.h"
#include <iostream>
#include <fstream>
using namespace std;

string SalesAssociate::get_info(){
    
	string allDetails;

	allDetails = name + "\n    Sales Associate #: " + number;
	return allDetails;
    
}

int SalesAssociate::get_SaNum() {
	
	return stoi(number);
}


void SalesAssociate::save_all(){
    
    ofstream ofs;
    ofs.open("data.txt", ofstream::out | ofstream::app);
    
    ofs << number << endl;
    ofs << name << endl;
    
    ofs.close();
}

void SalesAssociate::save_as_all(string filename) {

	ofstream ofs;
	ofs.open(filename.c_str(), ofstream::out | ofstream::app);

	ofs << number << endl;
	ofs << name << endl;

	ofs.close();
}

void SalesAssociate::raisecheck(){
    
    raise_check = true;
}

void SalesAssociate::raise_final(){
    
    raise = true;
}
