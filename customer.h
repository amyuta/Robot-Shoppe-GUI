#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "sales_associate.h"
using namespace std;

class Customer {

    friend SalesAssociate;
public:
    Customer(string c_name, string c_num, string sales_a) : name(c_name), number(c_num), sales_a(sales_a) {}

	string get_info();
	//string get_num();
	//string get_sales;
    void save_all();
	void save_as_all(string filename);
    
protected:
    string name;
    string number;
    string sales_a;
    //Order order;

};


#endif // CUSTOMER_H
