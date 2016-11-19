#ifndef SHOPPE_H
#define SHOPPE_H

//#include "std_lib_facilities.h"
#include "robot_model.h"
#include "order.h"
#include "customer.h"
#include "sales_associate.h"
#include "RobotPart.h"



class Shoppe {
public:
    //methods to create new
	void add_new_model(Robot_Model model, RobotPart head, RobotPart arm, RobotPart battery, RobotPart loco, RobotPart torso);
    void add_order(Order* order, int model);
    void add_customer(Customer* customer);
    void add_sa(SalesAssociate* sa);
    void create_newpart(RobotPart* part, int type);
	string all_parts();
    
    //methods to list/check/add parts
    void list_part_details(int type);
    bool check_parts(int c_bat, int c_torso, int c_arm);
    void list_parts(int type);
    void add_to_parts(int type, int quantity, int part_num);
    
    //method to list all sales associate
    string list_sa();
    void sa_raisecheck(int sa);
    void pb_raise(int sa);
    
    //method to list all customers
    string list_cust();
    
    //methods to make/show models
    void make_model(int type1, int type2, int type3, int type4, int type5, string mod_num, string mod_name);
    void show_models();
    int searchfor_part(int type, string num);
	string getModelString(int count);
    
    
    //method for orders
    void show_orders(string name, int num);
    void pay_order(int ord_num);
    void list_order(int sales_a);
    void paid_orders(int sa);
	int model_count();
    
    //save
    void save_info();
	void save_as_info(string filename);
	void load_data();

    int type;


private:
	vector<Robot_Model> robot_models;
	vector<Order*> orders;
	vector<Customer*> customers;
	vector<SalesAssociate*> sales_a;

    vector<RobotPart*> head;
    vector<RobotPart*> torso;
    vector<RobotPart*> battery;
    vector<RobotPart*> loco;
    vector<RobotPart*> arm;


};

#endif
#pragma once
