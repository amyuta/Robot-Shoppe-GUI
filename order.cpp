#include "order.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ostream>
#include <sstream>


using namespace std;

void Order::get_price(double price){
    total_cost = price + 100;
    tax = total_cost*.08;
    total_cost = total_cost+tax+shipping;
}

void Order::show_order(string name, int c_num){
    
    if(num == c_num){
        cout <<  "Robot Model: " <<model << endl << "Order Number: " << order_num << endl;
        order_paid();
    }
    else{
        return;
    }
    
}

void Order::save_all() {
    
    ofstream ofs;
    ofs.open("data.txt", ofstream::out | ofstream::app);
    
    ofs << order_num << endl;
    ofs << model << endl;
    ofs << name << endl;
    ofs << num << endl;
    ofs << sales_a << endl;
    
    ofs.close();
    
}

void Order::order_paid(){
    
    if(paid){
        
        cout << "Paid";
    }
    else{
        cout << "Not Paid";
    }
    
}

void Order::pay_now(int ord){
	if (order_num == ord) {
		paid = true;
	}
}

string Order::list_order(int sales_as){
    
	string order = "";
	stringstream s;
	s << setprecision(3) << total_cost;

    if(sales_a == sales_as){
        
		order = "Order Number: " + to_string(order_num) + "\n    Customer: " + name + "\n    Cost: $" + s.str();

		if (paid) {

			order = order + "\n    Paid\n\n";
		}
		else {
			order = order + "\n    Not Paid\n\n";
		}

		return order;
 
    }
    else{
        return order;
    }
    
}

string Order::cust_order(int cnum) {
	string order = "";
	stringstream s;
	s << setprecision(3) << total_cost;

	if (cnum == num) {

		order = "Order Number: " + to_string(order_num) + "\n    Customer: " + name + "\n    Cost: $" + s.str();

		if (paid) {

			order = order + "\n    Paid\n\n";
		}
		else {
			order = order + "\n    Not Paid\n\n";
		}

		return order;

	}
	else {
		return order;
	}

}

string Order::allOrder() {
	string order = "";
	stringstream s;
	s << setprecision(3) << total_cost;

	if (!paid) {
		order = "Order Number: " + to_string(order_num) + "\n    Customer: " + name + "\n    Cost: $" + s.str() + "\n    Not Paid\n\n";
		 
	}
	

	return order;


}


bool Order::paid_order(int sales_as){
    
    if(sales_a == sales_as && paid == true){
        
        cout <<  "Robot Model: " <<model << endl << "    Order Number: " << order_num << endl << "    ";
        return true;
    }
    else{
        return false;
    }
    
}





