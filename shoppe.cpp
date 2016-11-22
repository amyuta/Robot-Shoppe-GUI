#include "shoppe.h"
#include <iostream>
#include <fstream>
#include <iostream>
#include <stdexcept>


using namespace std;

// method to find model placement in vector. If -1 is returned, then model is not in vector.
int Shoppe::find_modelPlacement(int model_num) {

	int i = 0, mod;

	while (i < robot_models.size()) {

		mod = robot_models[i].get_modNum();

		if (mod == model_num) {
			return i;
		}
		i++;
	}

	return -1;

}

// method to find Sales associate placement in vector. It -1 is returned, then SA is not in vector.
int Shoppe::find_SaPlacement(int sa_num) {

	int i = 0, sa;

	while (i < sales_a.size()) {

		sa = sales_a[i]->get_SaNum();

		if (sa_num == sa) {

			return i;
		}
		i++;
	}

	return -1;
}




void Shoppe::create_newpart(RobotPart* part, int type){


    if(type == 1){
        head.push_back(part);
    }
    else if(type == 2){
        arm.push_back(part);
    }
    else if(type == 3){
        battery.push_back(part);
    }
    else if(type == 4){
        loco.push_back(part);
    }
    else if(type == 5){
        torso.push_back(part);
    }
}

string Shoppe::image_view(int i) {
	string imagename = "";
	imagename = robot_models[i].get_image() + ".jpg";
	return imagename;
}

string Shoppe::all_parts() {
	int i = 0;
	string allParts = "";

	allParts = "Heads:\n";
	while (i < head.size()) {

		allParts = allParts + to_string(i+1)+ ") " + head[i]->get_info(allParts) + "\n";
		i++;
	}
	//cout << i << endl;

	i = 0;
	allParts = allParts + "\nArms:\n";
	while (i < arm.size()) {

		allParts = allParts + to_string(i + 1) + ") " + arm[i]->get_info(allParts) + "\n";
		i++;
	}
	//cout << i << endl;
	i = 0;
	allParts = allParts + "\nBatteries:\n";
	while (i < battery.size()) {

		allParts = allParts + to_string(i + 1) + ") " + battery[i]->get_info(allParts) + "\n";
		i++;
	}
	//cout << i << endl;
	i = 0;
	allParts = allParts + "\nLocomotors:\n";
	while (i < loco.size()) {

		allParts = allParts + to_string(i + 1) + ") " + loco[i]->get_info(allParts) + "\n";
		i++;
	}
	//cout << i << endl;
	i = 0;
	allParts = allParts + "\nTorsos:\n";
	while (i < torso.size()) {

		allParts = allParts + to_string(i + 1) + ") " + torso[i]->get_info(allParts) + "\n";
		i++;
	}
	//cout << i << endl;
	return allParts;


}

void Shoppe::list_parts(int type){
    int i = 0;

    if(type == 1){
        while(i < head.size()){

            cout << "(" << i+1 << ")"<<" Head" << ": Part Number: ";
            head[i]->list_all();
            i++;
        }
    }
    else if(type == 2){
        while(i < arm.size()){

            cout << "(" << i+1 << ")"<<"Arm" << ": Part Number: ";
            arm[i]->list_all();
            i++;
        }
    }
    else if(type == 3){
        while(i < battery.size()){

            cout << "(" << i+1 << ")"<<"Battery" << ": Part Number: ";
            battery[i]->list_all();
            i++;
        }
    }
    else if(type == 4){
        while(i < loco.size()){

            cout << "(" << i+1 << ")"<<"Locomoter" << ": Part Number: ";
            loco[i]->list_all();
            i++;
        }
    }
    else if(type == 5){
        while(i < torso.size()){

            cout << "(" << i+1 << ")"<<"Torso" << ": Part Number: ";
            torso[i]->list_all();
            i++;
        }
    }
}

/*void Shoppe::add_to_parts(int type, int quantity, int part_num){

    int i = 0;

    if(type == 1){
        while(i < head.size()){
            head[i]->add_quan(part_num, quantity);
            i++;
        }

    }
    else if(type == 2){
        while(i < arm.size()){
            arm[i]->add_quan(part_num, quantity);
            i++;
        }
    }
    else if(type == 3){
        while(i < battery.size()){
            battery[i]->add_quan(part_num, quantity);
            i++;
        }
    }
    else if(type == 4){
        while(i < loco.size()){
            loco[i]->add_quan(part_num, quantity);
            i++;
        }
    }
    else if(type == 5){
        while(i < torso.size()){
            torso[i]->add_quan(part_num, quantity);
            i++;
        }
    }


}*/


void Shoppe::list_part_details(int type) {

    int i = 0;

    if (type == 1) {
        while (i < head.size()) {

            head[i]->list_all_detail();
            i++;
        }
    }
}

bool Shoppe:: check_parts(int c_bat, int c_torso, int c_arm){

    int batt, tor, arm_c;

    tor = torso[c_torso-1]->quan_count();
    batt = battery[c_bat-1]->quan_count();
    arm_c = arm[c_arm-1]->quan_count();

    if(batt >= tor){
        if(arm_c >= 2){
            return true;
        }
    }

    return false;

}

int Shoppe::model_count() {
	return robot_models.size();
}

void Shoppe::make_model(int type1, int type2, int type3, int type4, int type5, string mod_num, string mod_name, string image){

    int cost = 0;

    cost += head[type1]->get_cost();
    cost += arm[type2]->get_cost();
    cost += battery[type3]->get_cost();
    cost += loco[type4]->get_cost();
    cost += torso[type5]->get_cost();

    add_new_model(Robot_Model(mod_name, mod_num, image, cost), *head[type1], *arm[type2], *battery[type3], *loco[type4], *torso[type5]);

}

void Shoppe::add_new_model(Robot_Model model, RobotPart head, RobotPart arm, RobotPart battery, RobotPart loco, RobotPart torso) {
    robot_models.push_back(model);
    robot_models[robot_models.size()-1].make_robotmodel(head, arm, battery, loco, torso);

}

string Shoppe::getModelString(int count) {
	string curr;

	curr = robot_models[count].list_model();
	return curr;
}

void Shoppe:: show_models(){
    int i = 0;

    while(i < robot_models.size()){
        cout << endl <<"Model (" << i+1 << ")" << endl;
        robot_models[i].show_model();
        i++;
    }
}

void Shoppe::add_sa(SalesAssociate* sa){
    
    sales_a.push_back(sa);
}


string Shoppe::list_sa(){
	int i = 0;
	string allCust = "";

	while (i < sales_a.size()) {

		allCust = allCust + sales_a[i]->get_info() + "\n";
		i++;
	}

	return allCust;
}
void Shoppe::sa_raisecheck(int sa){
    
    sales_a[sa]->raisecheck();
}

void Shoppe::pb_raise(int sa){
    
    sales_a[sa]->raise_final();
}

void Shoppe::add_order(Order* order, int model ) {
    double price;
    
    price = robot_models[model].get_price();
    order->get_price(price);
    orders.push_back(order);
    
}

void Shoppe::show_orders(string name, int num){
    
    int i = 0;
    
    while(i < orders.size()){
        
        cout << "Order (" << i+1 << ") " << endl;
        orders[i]->show_order(name, num);
        i++;
        cout << endl;
    }
}

void Shoppe:: pay_order(int ord_num){
	int i = 0;

	while (i < orders.size()) {

		orders[i]->pay_now(ord_num);
		i++;
	
	}
}

void Shoppe::paid_orders(int sa){
    
    int i = 0, count = 0;
    bool prof_count;
    
    while(i < orders.size()){
        
        cout << endl;
        prof_count = orders[i]->paid_order(sa);
        if(prof_count){
            count++;
        }
        i++;
    }
    cout << endl << "Profit: " << count*100 << endl;
    
    
}

string Shoppe::list_order(int sales_a){
    
    int i = 0, profit;
	string order = "";
    
    while(i < orders.size()){
       
        order = order + orders[i]->list_order(sales_a) + "\n";
        i++;
    }

	profit = 100 * i;

	order = order + "\n" + "Total Profit: $" + to_string(profit);

	return order;
}


void Shoppe::add_customer(Customer* customer) {
  customers.push_back(customer);
}



string Shoppe::list_cust(){
    
    int i = 0;
	string allCust = "";

    while (i < customers.size()) {   
     
		allCust = allCust +customers[i]->get_info() + "\n";
        i++;
    }

	return allCust;
}

string Shoppe::list_custOrder(int cnum) {

	int i = 0;
	string allCust = "";

	while (i < orders.size()) {

		allCust = allCust + orders[i]->cust_order(cnum) + "\n";
		i++;
	}

	return allCust;
}

string Shoppe::AllOrder() {

	int i = 0;
	string allOrder = "";

	while (i < orders.size()) {

		allOrder = allOrder + orders[i]->allOrder() + "\n";
		i++;
	}

	return allOrder;
}




int Shoppe::searchfor_part(int type, string num){

	int i = 0;
	string pnum;

    if (type == 1) {

        while (i < head.size()) {
                pnum = head[i]->get_pnum();
            if (pnum == num) {
                return i;
            }
            i++;
        }
    }

    i = 0;

    if (type == 2) {

        while (i < arm.size()) {
                pnum = arm[i]->get_pnum();
            if (pnum == num) {
                return i;
            }
            i++;
        }
    }

    i = 0;

    if (type == 3) {

        while (i < battery.size()) {
                pnum = battery[i]->get_pnum();
            if ( pnum == num) {
                return i;
            }
            i++;
        }
    }

    i = 0;

    if (type == 4) {

        while (i < loco.size()) {
                pnum = loco[i]->get_pnum();
            if (pnum == num) {
                return i;
            }
            i++;
        }
    }

    i = 0;

    if (type == 5) {

        while (i < torso.size()) {
                pnum = torso[i]->get_pnum();
            if ( pnum == num) {
                return i;
            }
            i++;
        }
    }

    return 0;
}

void Shoppe::save_info(){
    
    

    cout << "Please wait while we save...\n";
    int i = 0;

    ofstream ofs;
    ofs.open("data.txt");   //print the head count for the loading process.
    ofs << head.size() << endl;
    ofs.close();

    while (i < head.size()){
        head[i]->save_all();
        i++;
    }

    i = 0;
    ofs.open("data.txt", ofstream::out | ofstream::app);   //print the arm count for the loading process.
    ofs << arm.size() << endl;
    ofs.close();

    while (i < arm.size()) {
        arm[i]->save_all();
        i++;
    }

    i = 0;
    ofs.open("data.txt", ofstream::out | ofstream::app);   //print the battery count for the loading process.
    ofs << battery.size() << endl;
    ofs.close();

    while (i < battery.size()) {
        battery[i]->save_all();
        i++;
    }

    i = 0;
    ofs.open("data.txt", ofstream::out | ofstream::app);   //print the loco count for the loading process.
    ofs << loco.size() << endl;
    ofs.close();
    
    while (i < loco.size()) {
        loco[i]->save_all();
        i++;
    }
    
    
    i = 0;
    ofs.open("data.txt", ofstream::out | ofstream::app);   //print the torso count for the loading process.
    ofs << torso.size() << endl;
    ofs.close();

    while (i < torso.size()) {
        torso[i]->save_all();
        i++;
    }

    i = 0;
    ofs.open("data.txt", ofstream::out | ofstream::app); //print the customer count for loading
    ofs << customers.size() << endl;
    ofs.close();

    while (i < customers.size()) {
        customers[i]->save_all();
        i++;
    }
    
    i = 0;
    ofs.open("data.txt", ofstream::out | ofstream::app); //print the sa count for loading
    ofs << sales_a.size() << endl;
    ofs.close();
    
    while (i < sales_a.size()) {
        sales_a[i]->save_all();
        i++;
    }

    i = 0;
    ofs.open("data.txt", ofstream::out | ofstream::app); //print the model count for the loading
    ofs << robot_models.size() << endl;
    ofs.close();

    while (i < robot_models.size()) {
        robot_models[i].save_alls();
        i++;
    }
    
    /*
    i = 0;
    ofs.open("data.txt", ofstream::out | ofstream::app); //print the order count for the loading
    ofs << orders.size() << endl;
    ofs.close();
    
    while (i < orders.size()) {
        orders[i]->save_all();
        i++;
    }
     */


}

void Shoppe::save_as_info(string filename) {



	cout << "Please wait while we save...\n";
	int i = 0;

	ofstream ofs;
	ofs.open(filename.c_str());   //print the head count for the loading process.
	ofs << head.size() << endl;
	ofs.close();

	while (i < head.size()) {
		head[i]->save_as_all(filename);
		i++;
	}

	i = 0;
	ofs.open(filename.c_str(), ofstream::out | ofstream::app);   //print the arm count for the loading process.
	ofs << arm.size() << endl;
	ofs.close();

	while (i < arm.size()) {
		arm[i]->save_as_all(filename);
		i++;
	}

	i = 0;
	ofs.open(filename.c_str(), ofstream::out | ofstream::app);   //print the battery count for the loading process.
	ofs << battery.size() << endl;
	ofs.close();

	while (i < battery.size()) {
		battery[i]->save_as_all(filename);
		i++;
	}

	i = 0;
	ofs.open(filename.c_str(), ofstream::out | ofstream::app);   //print the loco count for the loading process.
	ofs << loco.size() << endl;
	ofs.close();

	while (i < loco.size()) {
		loco[i]->save_as_all(filename);
		i++;
	}


	i = 0;
	ofs.open(filename.c_str(), ofstream::out | ofstream::app);   //print the torso count for the loading process.
	ofs << torso.size() << endl;
	ofs.close();

	while (i < torso.size()) {
		torso[i]->save_as_all(filename);
		i++;
	}

	i = 0;
	ofs.open(filename.c_str(), ofstream::out | ofstream::app); //print the customer count for loading
	ofs << customers.size() << endl;
	ofs.close();

	while (i < customers.size()) {
		customers[i]->save_as_all(filename);
		i++;
	}

	i = 0;
	ofs.open(filename.c_str(), ofstream::out | ofstream::app); //print the sa count for loading
	ofs << sales_a.size() << endl;
	ofs.close();

	while (i < sales_a.size()) {
		sales_a[i]->save_as_all(filename);
		i++;
	}

	i = 0;
	ofs.open(filename.c_str(), ofstream::out | ofstream::app); //print the model count for the loading
	ofs << robot_models.size() << endl;
	ofs.close();

	while (i < robot_models.size()) {
		robot_models[i].save_as_alls(filename);
		i++;
	}

	/*
	i = 0;
	ofs.open("data.txt", ofstream::out | ofstream::app); //print the order count for the loading
	ofs << orders.size() << endl;
	ofs.close();

	while (i < orders.size()) {
	orders[i]->save_all();
	i++;
	}
	*/


}


