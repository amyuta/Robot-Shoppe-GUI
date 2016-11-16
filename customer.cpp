#include "customer.h"
#include <stdio.h>
#include <fstream>
#include <ostream>
#include <iostream>
using namespace std;

void Customer::save_all(){

    ofstream ofs;
    ofs.open("data.txt", ofstream::out | ofstream::app);

            ofs << number << endl;
            ofs << name << endl;
            ofs << sales_a << endl;

            ofs.close();
}

void Customer::save_as_all(string filename) {

	ofstream ofs;
	ofs.open(filename.c_str(), ofstream::out | ofstream::app);

	ofs << number << endl;
	ofs << name << endl;
	ofs << sales_a << endl;

	ofs.close();
}


string Customer::get_info() {

	string allDetails;

	allDetails = name + "\n    Customer #: " + number + "\n    Sales Associate #: " + sales_a;
	return allDetails;
}



