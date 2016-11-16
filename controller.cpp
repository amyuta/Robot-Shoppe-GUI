#include "controller.h"
#include "RobotPart.h"
#include "shoppe.h"
#include "Head.h"
#include "torso.h"
#include "Arm.h"
#include "Locomotor.h"
#include "battery.h"
#include "order.h"
#include "sales_associate.h"
#include "customer.h"

#include <iostream>
#include<fstream>
#include<string>
using namespace std;

void Controller::cli() {
	int cmd = -1;
	while (cmd != 0) {
		view.show_mainmenu();
		cout << "Command? ";
		cin >> cmd;
		cin.ignore(); // consume \n
		execute_cmd(cmd);
	}
}

void Controller:: execute_cmd(int cmd) {

    if (cmd == 1) {
        view.show_pmmenu();
        cout << "Command? ";
        cin >> cmd;
        cin.ignore(); // consume \n

        if(cmd == 1){
            execute_createnewpart(cmd);
        }
        else if (cmd == 2){
            execute_createrobotmodel();
        }
        else if (cmd == 9) {
            view.show_mainmenu();
        }
        else {
            view.show_pmmenu();
        }
    }
    else if (cmd == 2) {
        view.show_bcmenu();
        cout << "Command? ";
        cin >> cmd;
        cin.ignore(); // consume \n

        if(cmd == 9){
            view.show_mainmenu();
        }
        else if(cmd == 1){
            execute_showrobotmodels();
        }
        else if(cmd == 2){
            show_order();
        }
        
    }
    else if (cmd == 3) {
        view.show_samenu();
        cout << "Command? ";
        cin >> cmd;
        cin.ignore(); // consume \n

        if(cmd == 9){
            view.show_mainmenu();
        }
        else if (cmd == 1) {
            new_customer();
        }
        else if(cmd == 2){
            make_order();
        }
        else if(cmd == 3){
            list_orders();
        }
        else if(cmd == 4){
            
            sa_raise();
        }
        
    }
    else if (cmd == 4) {
        view.show_pbmenu();
        cout << "Command? ";
        cin >> cmd;
        cin.ignore(); // consume \n

        if(cmd == 1){
            cout << "\nSales Associate: \n";
            shoppe.list_sa();
            cout << "\n";
            execute_cmd(4);
        }
        else if(cmd == 2){
            list_orders();
            
        }
        else if(cmd == 3){
            
            sales_report();
        }
        else if(cmd == 4){
            new_sa();
        }
        else if(cmd == 5){
            pb_raise();
        }
        else if(cmd == 9){
            view.show_mainmenu();
        }
    }
    else if(cmd == 5){

        cout<< "Please wait while we load files...\n";
        load_data();
    }
    else if (cmd == 6) {
        shoppe.save_info();
    }
    else if (cmd == 9) {
        exit(1);
    }
    else {
        view.show_mainmenu();
    }

}

void Controller::execute_createnewpart(int cmd) {
    int type, option, part_num, power, batt_count, max_speed, energy, quantity, add_part;
    double weight, cost;
    string descrip, type_name;

    cout<< "\n(1) Create New Part\n(2) Add to Existing Part\n\n";
    cout<< "Command? ";
    cin>>option;
    cin.ignore();


    if(option == 1){
        cout << "\nFirst select the part type.\n(1) Head\n(2) Arm\n(3) Battery\n(4) Locomotor\n(5) Torso\n\n";
        cout << "Command? ";
        cin >> type;
        cin.ignore();
        cout << endl;

        if (type == 1) {
            cout << "Please enter the following details about the Head.\n";
            cout << "Part #: ";
            cin >> part_num;
            cin.ignore();
            cout << "Weight (lbs): ";
            cin >> weight;
            cin.ignore();
            cout << "Cost ($): ";
            cin >> cost;
            cin.ignore();
            cout << "Quantity: ";
            cin >> quantity;
            cin.ignore();
            cout << "Description: ";
            getline(cin, descrip);

            shoppe.create_newpart(new Head(part_num, weight, cost, descrip, quantity), 1);


        }

        if (type == 2) {
            cout << "Please enter the following details about the Arm.\n";
            cout << "Part #: ";
            cin >> part_num;
            cin.ignore();
            cout << "Weight (lbs): ";
            cin >> weight;
            cin.ignore();
            cout << "Cost ($): ";
            cin >> cost;
            cin.ignore();
            cout << "Quantity: ";
            cin >> quantity;
            cin.ignore();
            cout << "Power (Watts): ";
            cin >> power;
            cin.ignore();
            cout << "Description: ";
            getline(cin, descrip);

            shoppe.create_newpart(new Arm(part_num, weight, cost, descrip, power, quantity), 2);


        }

        if (type == 3) {
            cout << "Please enter the following details about the Battery.\n";
            cout << "Part #: ";
            cin >> part_num;
            cin.ignore();
            cout << "Weight (lbs): ";
            cin >> weight;
            cin.ignore();
            cout << "Cost ($): ";
            cin >> cost;
            cin.ignore();
            cout << "Quantity: ";
            cin >> quantity;
            cin.ignore();
            cout << "Energy (KWHr): ";
            cin >> energy;
            cin.ignore();
            cout << "Description: ";
            getline(cin, descrip);

            shoppe.create_newpart(new Battery(part_num, weight, cost, descrip, energy, quantity), 3);


        }

        if (type == 4) {
            cout << "Please enter the following details about the Locomotor.\n";
            cout << "Part #: ";
            cin >> part_num;
            cin.ignore();
            cout << "Weight (lbs): ";
            cin >> weight;
            cin.ignore();
            cout << "Cost ($): ";
            cin >> cost;
            cin.ignore();
            cout << "Quantity: ";
            cin >> quantity;
            cin.ignore();
            cout << "Power (Watts): ";
            cin >> power;
            cin.ignore();
            cout << "Max Speed (MPH): ";
            cin >> max_speed;
            cin.ignore();
            cout << "Description: ";
            getline(cin, descrip);

            shoppe.create_newpart(new Locomotor(part_num,weight, cost, descrip, power, max_speed, quantity), 4);


        }

        if (type == 5) {
            cout << "Please enter the following details about the Torso.\n";
            cout << "Part #: ";
            cin >> part_num;
            cin.ignore();
            cout << "Weight (lbs): ";
            cin >> weight;
            cin.ignore();
            cout << "Cost ($): ";
            cin >> cost;
            cin.ignore();
            cout << "Quantity: ";
            cin >> quantity;
            cin.ignore();
            cout << "Battery Component Count: ";
            cin >> batt_count;
            cin.ignore();
            cout << "Description: ";
            getline(cin, descrip);

            shoppe.create_newpart(new Torso(part_num, weight, cost, descrip, batt_count, quantity), 5);
        }
    }
    else if(option == 2){

        cout << "\n\nFirst select the part type you wish to add to.\n(1) Head\n(2) Arm\n(3) Battery\n(4) Locomotor\n(5) Torso\n\n";
        cout << "Command? ";
        cin >> type;
        cin.ignore();
        cout << endl;

        if(type == 1 || type == 2 || type == 3 || type == 4 || type == 5){

            view.list_parts();
            shoppe.list_parts(type);
            cout << "\nPart Number you wish to add to: ";
            cin >> add_part;
            cin.ignore();
            cout << "Quantity: ";
            cin >> quantity;
            cin.ignore();

            shoppe.add_to_parts(type, quantity, add_part);

        }


    }

    execute_cmd(1);
}


void Controller::execute_createrobotmodel(){

    int part_type1, part_type2, part_type3, part_type4, part_type5, model_num, command;
    string model_name;
    bool makepart;

    cout << "Enter Model Name: \n";
    getline(cin, model_name);

    cout << "Enter Model Number: \n";
    cin >> model_num;
    cin.ignore();

    cout << "Chose a Head: \n";
    shoppe.list_parts(1);
    cout << endl <<"Option?: ";
    cin >> part_type1;
    cin.ignore();

    cout << "\nChose an Arm: \n";
    shoppe.list_parts(2);
    cout << endl <<"Option?: ";
    cin >> part_type2;
    cin.ignore();

    //Maybe ask, How many batteries.. instead?
    cout << "\nChose a Battery: \n";
    shoppe.list_parts(3);
    cout << endl <<"Option?: ";
    cin >> part_type3;
    cin.ignore();

    cout << "\nChose a Locomotor: \n";
    shoppe.list_parts(4);
    cout << endl <<"Option?: ";
    cin >> part_type4;
    cin.ignore();

    cout << "\nChose a Torso: \n";
    shoppe.list_parts(5);
    cout << endl <<"Option?: ";
    cin >> part_type5;
    cin.ignore();

    makepart = shoppe.check_parts(part_type3, part_type5, part_type2);

    if(makepart){
        shoppe.make_model(part_type1-1, part_type2-1, part_type3-1, part_type4-1, part_type5-1, model_num, model_name);
        cout << "Model Created.\n";
    }
    else{

        cout << "Not enough parts to make model.\n";
        cout << "(1) Main Menu\n";
        cout << "(2) Create Menu\n";
        cout << "Command? ";
        cin >> command;
        cin.ignore();

        if(command == 1){
            cli();
        }
        else if(command == 2){
            execute_cmd(1);
        }

    }
}

void Controller::new_customer(){

    string c_name;
    int c_num, sales_a;

     cout << "Enter Customer Name: ";
    getline(cin, c_name);

    cout << "Enter Customer Number: ";
    cin >> c_num;
    cin.ignore();
    
    cout << "\nChoose a Sales Associate:\n";
    shoppe.list_sa();
    cout << "\n\nOption? ";
    cin >> sales_a;
    cin.ignore();

    shoppe.add_customer( new Customer(c_name, c_num, sales_a-1));

}

void Controller::new_sa(){
    
    string name;
    int num;
    
    cout << "Enter Sales Associate name: ";
    getline(cin, name);
    cout << "Enter Sales Associate number: " ;
    cin >> num;
    cin.ignore();
    
    shoppe.add_sa(new SalesAssociate(name, num));
    
}

void Controller::execute_showrobotmodels(){
    int cmd, num, sales_a, model;
    string name;
    
    shoppe.show_models();
    
    cout << "\n(1) Buy a Model\n";
    cout << "(2) Exit to Main Menu\n\n";
    cout << "Command? ";
    cin >> cmd;
    
    if(cmd == 1){
        cout<< "\nWhich Model would you like to buy?: ";
        cin >> model;
        cin.ignore();
        
        cout << "Enter your name: ";
        getline(cin, name);
        
        cout << "Enter your number: " ;
        cin >> num;
        cin.ignore();
        
        cout << "\nChoose a Sales Associate:\n";
        shoppe.list_sa();
        cout << "\n\nCommand? ";
        cin >> sales_a;
        cin.ignore();
        
        shoppe.add_customer( new Customer(name, num, sales_a-1));
        
        cout << "\nPlease wait for Sales Associate...\n\n";
        view.show_samenu2();
        cout << "\nCommand? ";
        cin >> cmd;
        cin.ignore();
        
        if(cmd == 1){
            
            place_order(model, name, num, sales_a-1);
        }
        
        
    }
    else if(cmd == 2){
        cli();
    }
}

void Controller::make_order(){
    
    string name;
    int num, sales_a, model, cmd;
    
    cout << endl;
    shoppe.list_cust();
    
    cout << "\nIs the Customer listed?\n" << endl << "(1) Yes" << endl << "(2) No" << endl << endl << "Command? ";
    cin >> cmd;
    
    if(cmd == 1){
        shoppe.show_models();
    
        cout<< "\nWhich Model is being purchased?: ";
        cin >> model;
        cin.ignore();
    
        cout << "\nEnter Customer's name: ";
        getline(cin, name);
    
        cout << "Enter Customer's number: " ;
        cin >> num;
        cin.ignore();
    
        cout << "Sales Associate:\n";
        shoppe.list_sa();
        cout << "\nCommand? ";
        cin >> sales_a;
        cin.ignore();
    
        cout << endl;
        place_order(model, name, num, sales_a-1);
    }
    else{
        
        cout << "Add new Customer\n";
        new_customer();
        make_order();
    }
    
}

void Controller::place_order(int model, string name, int num, int sales_a){
    
    int o_num;
    
    cout << "Enter Order Number: ";
    cin >> o_num;
    cin.ignore();
    
    shoppe.add_order(new Order(o_num, model, name, num, sales_a), model-1);
    
    cout << "\nOrder Placed.";
    cli();
}

void Controller::show_order(){
    
    string name;
    int num, cmd, order;
    
    cout<< "\nEnter your name: ";
    getline(cin, name);
    cout << "Enter your number: ";
    cin >> num;
    cin.ignore();
    cout << endl;
    
    shoppe.show_orders(name, num);
    
    cout << endl << "(1) Pay a bill\n" << "(2) Main Menu" << endl << endl << "Command? ";
    cin >> cmd;
    cin.ignore();
    
    if(cmd == 1){
        cout << "Enter order to be paid: ";
        cin >> order;
        cin.ignore();
        shoppe.pay_order(order-1);
        cout << endl << "Bill Paid" << endl;
        
    }
    else{
        cli();
    }
    
}

void Controller::list_orders(){
    
    int sales_a;
    
    cout << "\nChoose a Sales Associate:\n";
    shoppe.list_sa();
    cout << "\n\nOption? ";
    cin >> sales_a;
    cin.ignore();
    
    shoppe.list_order(sales_a-1);
}

void Controller::sa_raise(){
    
    int sales_a;
    
    cout << "\nChoose a Sales Associate:\n";
    shoppe.list_sa();
    cout << "\nCommand? ";
    cin >> sales_a;
    cin.ignore();

    shoppe.sa_raisecheck(sales_a-1);

}

void Controller::pb_raise(){
    
    int sales_a;
    
    cout << "\nLook at Sales Report for Justification\n";
    cout << "Choose a Sales Associate:\n";
    shoppe.list_sa();
    cout << "\nOption? ";
    cin >> sales_a;
    cin.ignore();
    
    shoppe.pb_raise(sales_a-1);
    
    cout << "Raise Given to Sales Associate";

}

void Controller::sales_report(){
    
    int sales_a;
    
    cout << "\nChoose a Sales Associate:\n";
    shoppe.list_sa();
    cout << "\n\nOption? ";
    cin >> sales_a;
    cin.ignore();
    
    shoppe.paid_orders(sales_a-1);
    
    
}

void Controller::load_data() { //load saved data
    int part_num;
    int weight;
    int cost;
    int quantity;
    int energy;
    int batt_count;
    string descrip;
    string temp;
    int i = 0;
    int numcount;
    int power;
    ifstream ifs("data.txt"); //load from file

    getline(ifs, temp);
    numcount = stoi(temp);

    while(i < numcount) {
        getline(ifs, temp);
        part_num = stoi(temp);
        getline(ifs, temp);
        weight = stoi(temp);
        getline(ifs, temp);
        cost = stoi(temp);
        getline(ifs, temp);
        quantity = stoi(temp);
        getline(ifs, descrip);

        shoppe.create_newpart(new Head(part_num, weight, cost, descrip, quantity), 1);
        i++;
    }
    i = 0;

    getline(ifs, temp);
    numcount = stoi(temp);

	while (i < numcount) {
        getline(ifs, temp);
		part_num = stoi(temp);
		getline(ifs, temp);
		weight = stoi(temp);
		getline(ifs, temp);
		cost = stoi(temp);
		getline(ifs, temp);
		quantity = stoi(temp);
		getline(ifs, temp);
		power = stoi(temp);
		getline(ifs, descrip);
        

		shoppe.create_newpart(new Arm(part_num, weight, cost, descrip, power, quantity), 2);
        i++;
	}
    
    i = 0;
    getline(ifs, temp);
    numcount = stoi(temp);
    
    while (i < numcount) {
        getline(ifs, temp);
        part_num = stoi(temp);
        getline(ifs, temp);
        weight = stoi(temp);
        getline(ifs, temp);
        cost = stoi(temp);
        getline(ifs, temp);
        quantity = stoi(temp);
        getline(ifs, temp);
        energy = stoi(temp);
        getline(ifs, descrip);
        
        shoppe.create_newpart(new Battery(part_num, weight, cost, descrip, energy, quantity), 3);
        i++;
    }

	i = 0;
	int max_speed;
    getline(ifs, temp);
    numcount = stoi(temp);

	while (i < numcount) {
        getline(ifs, temp);
		part_num = stoi(temp);
		getline(ifs, temp);
		weight = stoi(temp);
		getline(ifs, temp);
		cost = stoi(temp);
		getline(ifs, temp);
		quantity = stoi(temp);
		getline(ifs, temp);
		power = stoi(temp);
		getline(ifs, temp);
		max_speed = stoi(temp);
		getline(ifs, descrip);

        shoppe.create_newpart(new Locomotor(part_num,weight, cost, descrip, power, max_speed, quantity), 4);
        i++;
	}


	i = 0;
	getline(ifs, temp);
    numcount = stoi(temp);

	while (i < numcount) {
        getline(ifs, temp);
		part_num = stoi(temp);
		getline(ifs, temp);
		weight = stoi(temp);
		getline(ifs, temp);
		cost = stoi(temp);
		getline(ifs, temp);
		quantity = stoi(temp);
		getline(ifs, temp);
		batt_count = stoi(temp);
		getline(ifs, descrip);

		shoppe.create_newpart(new Torso(part_num, weight, cost, descrip, batt_count, quantity), 5);
        i++;
	}


	i = 0;
	string c_name;
	int c_num, sales_a;
	getline(ifs, temp);
    numcount = stoi(temp);

    while (i < numcount) {
        getline(ifs, temp);
        c_num = stoi(temp);
        getline(ifs, c_name);
        getline(ifs, temp);
        sales_a = stoi(temp);
        shoppe.add_customer( new Customer(c_name, c_num, sales_a));
        i++;
    }
    
    i = 0;
    int sa_num;
    string sa_name;
    getline(ifs, temp);
    numcount = stoi(temp);
    
    while (i < numcount) {
        getline(ifs, temp);
        sa_num = stoi(temp);
        getline(ifs, sa_name);
        shoppe.add_sa(new SalesAssociate(sa_name, sa_num));
        i++;
        
    }

    
    i = 0;
    int model_num;
    int price;
    int check;
    int headm, armm, torsom, battm, locom;
    string name;
    getline(ifs, temp);
    numcount = stoi(temp);

    while (i < numcount) {
        getline(ifs, name);
        getline(ifs, temp);
        model_num = stoi(temp);
        
        getline(ifs, temp);
        price = stoi(temp);
        
        getline(ifs, temp);
        check = stoi(temp); // part number
        headm = shoppe.searchfor_part(1, check);
        getline(ifs, temp);
        getline(ifs, temp);
        getline(ifs, temp);
        getline(ifs, temp);
        
        getline(ifs, temp);
        check = stoi(temp);
        armm = shoppe.searchfor_part(2, check);
        getline(ifs, temp);
        getline(ifs, temp);
        getline(ifs, temp);
        getline(ifs, temp);
        getline(ifs, temp);
        
        check = stoi(temp);
        battm = shoppe.searchfor_part(3, check);
        getline(ifs, temp);
        getline(ifs, temp);
        getline(ifs, temp);
        getline(ifs, temp);
        getline(ifs, temp);
        
        check = stoi(temp);
        locom = shoppe.searchfor_part(4, check);
        getline(ifs, temp);
        getline(ifs, temp);
        getline(ifs, temp);
        getline(ifs, temp);
        getline(ifs, temp);
        //getline(ifs, temp);
        
        check = stoi(temp);
        torsom = shoppe.searchfor_part(5, check);
        getline(ifs, temp);
        getline(ifs, temp);
        getline(ifs, temp);
        getline(ifs, temp);
        getline(ifs, temp);
        
        shoppe.make_model(headm, armm, battm, locom, torsom, model_num, name);
        i++;
    }
    
    /*
    i = 0;
    int o_num, o_model, oc_num, o_sales;
    string o_name;
    numcount = stoi(temp);
    
    while (i < numcount) {
        getline(ifs, temp);
        o_num = stoi(temp);
        getline(ifs, temp);
        o_model = stoi(temp);
        getline(ifs, o_name);
        getline(ifs, temp);
        oc_num = stoi(temp);
        getline(ifs, temp);
        o_sales = stoi(temp);
        shoppe.add_order(new Order(o_num, o_model, o_name, oc_num, o_sales), o_model-1);
        i++;
        
    }
     */


}
