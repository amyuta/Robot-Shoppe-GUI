#ifndef ORDER_H
#define ORDER_H
//#include "std_lib_facilities.h"
#include<string>

using namespace std;

class Order {
public:
    Order(int o_num, int robo_model, string c_name, int c_num, int sales_a)
        : order_num(o_num), model(robo_model), name(c_name), num(c_num), sales_a(sales_a) {}

    void get_price(double price);
    void show_order(string name, int c_num);
    void order_paid();
    void pay_now();
    void save_all();
    void list_order(int sales_as);
    bool paid_order(int sales_as);

private:
    int order_num;
    int model;
    int sales_a;
    double total_cost;
    double shipping = 5.0;
    double tax;
    string name;
    int num;
    bool paid = false;

};
#endif // ORDER_H
