#include "order.h"
#include <iostream>
#include <fstream>

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

void Order::pay_now(){
    paid = true;
}

void Order::list_order(int sales_as){
    
    if(sales_a == sales_as){
        
        cout <<  "Robot Model: " <<model << endl << "    Order Number: " << order_num << endl << "    ";
        order_paid();
 
    }
    else{
        return;
    }
    
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





