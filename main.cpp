#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/fl_ask.H>
#include <Fl/Fl_PNG_Image.H>
#include <Fl/Fl_JPEG_Image.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Return_Button.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_File_Browser.H>

#include <iostream>
#include<fstream>
#include <string>
#include "shoppe.h"
#include "view.h"
#include "main.h"
#include "Head.h"
#include "Arm.h"
#include "battery.h"
#include "Locomotor.h"
#include "torso.h"
#include "RobotPart.h"
#include "customer.h"
#include "sales_associate.h"
#include "controller.h"


//
// Declarations (we'll define later, just need to declare some variables!)
//
void create_headCB(Fl_Widget* w, void* p);
void cancel_headCB(Fl_Widget* w, void* p);
void create_armCB(Fl_Widget* w, void* p);
void cancel_armCB(Fl_Widget* w, void* p);
void create_battCB(Fl_Widget* w, void* p);
void cancel_battCB(Fl_Widget* w, void* p);
void create_locoCB(Fl_Widget* w, void* p);
void cancel_locoCB(Fl_Widget* w, void* p);
void create_torsoCB(Fl_Widget* w, void* p);
void cancel_torsoCB(Fl_Widget* w, void* p);
void loadchooseCB(Fl_Widget* w, void* p);
void loadCB(Fl_Widget* w, void* p);
void load_data();
void load_choice_data(string filename);
int showCatalog(Fl_Widget* w, void* p);
void create_modelCB(Fl_Widget* w, void* p);
void cancel_modelCB(Fl_Widget* w, void* p);
int createOrder(Fl_Widget* w, void* p);
void create_custCB(Fl_Widget* w, void* p);
void cancel_custCB(Fl_Widget* w, void* p);
void create_saCB(Fl_Widget* w, void* p);
void cancel_saCB(Fl_Widget* w, void* p);
int createModel(Fl_Widget* w, void* p);

class Robot_Part_Dialog;
class Head_Dialog;
class Arm_Dialog;
class Battery_Dialog;
class Locomotor_Dialog;
class Torso_Dialog;
class Model_Dialog;

class Customer_Dialog;
class SalesAssociate_Dialog;

//
// Widgets
//
Fl_Window *win, *custReports, *saReports, *models, *catalog, *order, *loader;
Fl_Menu_Bar *menubar;
Fl_Box *box;
Fl_Input *t1, *t2, *t3, *t4, *t5, *t6, *t7, *rm_part_number, *rm_name, *rm_head, *rm_arm, *rm_batt, *rm_loco, *rm_torso;;
View *view;
Fl_Box *jpgbox;
Fl_JPEG_Image *weljpg;
Robot_Part_Dialog *rp_dlg;
Head_Dialog *head_dlg;
Arm_Dialog *arm_dlg;
Battery_Dialog *batt_dlg;
Locomotor_Dialog *loco_dlg;
Torso_Dialog *torso_dlg;
Model_Dialog *model_dlg;


Customer_Dialog *cust_dlg;
SalesAssociate_Dialog *sa_dlg;
Shoppe shoppe;


void load_choice_data(string filename) { //load saved data
	string part_num;
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
	ifstream ifs(filename); //load from file

	getline(ifs, temp);
	numcount = stoi(temp);

	while (i < numcount) {
		getline(ifs, part_num);
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
		getline(ifs, part_num);
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
		getline(ifs, part_num);
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
		getline(ifs, part_num);
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

		shoppe.create_newpart(new Locomotor(part_num, weight, cost, descrip, power, max_speed, quantity), 4);
		i++;
	}


	i = 0;
	getline(ifs, temp);
	numcount = stoi(temp);

	while (i < numcount) {
		getline(ifs, part_num);
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
	string c_name, c_num, sales_a;
	getline(ifs, temp);
	numcount = stoi(temp);

	while (i < numcount) {
		getline(ifs, c_num);
		getline(ifs, c_name);
		getline(ifs, sales_a);
		shoppe.add_customer(new Customer(c_name, c_num, sales_a));
		i++;
	}

	i = 0;
	string sa_name, sa_num;
	getline(ifs, temp);
	numcount = stoi(temp);

	while (i < numcount) {
		getline(ifs, sa_num);
		getline(ifs, sa_name);
		shoppe.add_sa(new SalesAssociate(sa_name, sa_num));
		i++;

	}


	i = 0;
	int price;
	string check;
	int headm, armm, torsom, battm, locom;
	string name, model_num;
	getline(ifs, temp);
	numcount = stoi(temp);

	while (i < numcount) {
		getline(ifs, name);
		getline(ifs, model_num);

		getline(ifs, temp);
		price = stoi(temp);

		getline(ifs, check);
		headm = shoppe.searchfor_part(1, check);
		getline(ifs, temp);
		getline(ifs, temp);
		getline(ifs, temp);
		getline(ifs, temp);

		getline(ifs, check);
		//check = stoi(temp);
		armm = shoppe.searchfor_part(2, check);
		getline(ifs, temp);
		getline(ifs, temp);
		getline(ifs, temp);
		getline(ifs, temp);
		getline(ifs, check);

		//check = stoi(temp);
		battm = shoppe.searchfor_part(3, check);
		getline(ifs, temp);
		getline(ifs, temp);
		getline(ifs, temp);
		getline(ifs, temp);
		getline(ifs, check);

		//check = stoi(temp);
		locom = shoppe.searchfor_part(4, check);
		getline(ifs, temp);
		getline(ifs, temp);
		getline(ifs, temp);
		getline(ifs, temp);
		getline(ifs, check);
		//getline(ifs, temp);

		//check = stoi(temp);
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

int createOrder(Fl_Widget* w, void* p) {
	order = new Fl_Window(660, 500, "Create Robot Model Order");

	Fl_Tabs* ordertabs = new Fl_Tabs(10, 10, 400, 200); 
	{
		Fl_Group* grup = new Fl_Group(20, 30, 280, 170, "Customers");
		{
			string AllCusts = shoppe.list_cust();
			char *testing = new char[AllCusts.length() + 1];
			strcpy(testing, AllCusts.c_str());

			Fl_Text_Buffer *buff = new Fl_Text_Buffer();
			Fl_Text_Display *disp = new Fl_Text_Display(20, 40, 380 - 40, 180 - 40);
			disp->buffer(buff);
			win->resizable(*disp);
			win->show();
			buff->text(testing);
		}
		grup->end();
		Fl_Group* grup2 = new Fl_Group(20, 30, 280, 170, "Sales Associates");
		{
			//Turn string into Char array
			string AllSa = shoppe.list_sa();
			char *testing = new char[AllSa.length() + 1];
			strcpy(testing, AllSa.c_str());

			Fl_Text_Buffer *buff = new Fl_Text_Buffer();
			Fl_Text_Display *disp = new Fl_Text_Display(20, 40, 380 - 40, 180 - 40);
			disp->buffer(buff);
			win->resizable(*disp);
			win->show();
			buff->text(testing);

		}
		grup2->end();
		Fl_Group* grup3 = new Fl_Group(20, 30, 280, 170, "Models");
		{
			int counter = shoppe.model_count();
			int y = 40;

			if (counter == 0) {
				Fl_Text_Buffer *buff = new Fl_Text_Buffer();
				Fl_Text_Display *disp = new Fl_Text_Display(20, y, 380, 60);
				disp->buffer(buff);

				buff->text("No Created Models");
			}
			for (int i = 0; i < counter; i++) {
				string modelInfo = shoppe.getModelString(i);
				char *testing = new char[modelInfo.length() + 1];
				strcpy(testing, modelInfo.c_str());

				Fl_Text_Buffer *buff = new Fl_Text_Buffer();
				Fl_Text_Display *disp = new Fl_Text_Display(20, y, 400, 80, "");
				disp->buffer(buff);

				buff->text(testing);

				y = y + 100;
			}

		}
		grup3->end();
	}
	ordertabs->end();
	order->end();
	order->show();
	order->set_non_modal();
	return(Fl::run());

}

int showCatalog(Fl_Widget* w, void* p) {
	catalog = new Fl_Window(660, 500, "Robot Model Catalog");

	int counter = shoppe.model_count();
	int y = 30;

	if (counter == 0) {
		Fl_Text_Buffer *buff = new Fl_Text_Buffer();
		Fl_Text_Display *disp = new Fl_Text_Display(20, y, 400, 60, "Models");
		disp->buffer(buff);

		buff->text("No Created Models");
	}
	for (int i = 0; i < counter; i++) {
		string modelInfo = shoppe.getModelString(i);
		char *testing = new char[modelInfo.length() + 1];
		strcpy(testing, modelInfo.c_str());

		Fl_Text_Buffer *buff = new Fl_Text_Buffer();
		Fl_Text_Display *disp = new Fl_Text_Display(20, y, 400, 80, "");
		disp->buffer(buff);

		buff->text(testing);

		y = y + 100;
	}
	catalog->end();
	catalog->show();
	catalog->set_non_modal();

	return(Fl::run());
}

int createModel(Fl_Widget* w, void* p) {
	models = new Fl_Window(660, 500, "New Model");

	string AllParts = shoppe.all_parts();
	char *testing = new char[AllParts.length() + 1];
	strcpy(testing, AllParts.c_str());

	Fl_Text_Buffer *buff = new Fl_Text_Buffer();
	Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 340 - 40, 480 - 40, "Part Lists");
	disp->buffer(buff);

	buff->text(testing);



	rm_part_number = new Fl_Input(425, 30, 210, 25, "Part #:");
	rm_part_number->align(FL_ALIGN_LEFT);

	rm_name = new Fl_Input(425, 60, 210, 25, "Model Name:");
	rm_name->align(FL_ALIGN_LEFT);

	rm_head = new Fl_Input(425, 90, 210, 25, "Head #:");
	rm_head->align(FL_ALIGN_LEFT);

	rm_arm = new Fl_Input(425, 120, 210, 25, "Arm #:");
	rm_arm->align(FL_ALIGN_LEFT);

	rm_batt = new Fl_Input(425, 150, 210, 25, "Battery #:");
	rm_batt->align(FL_ALIGN_LEFT);

	rm_loco = new Fl_Input(425, 180, 210, 25, "Locomotor #:");
	rm_loco->align(FL_ALIGN_LEFT);

	rm_torso = new Fl_Input(425, 210, 210, 25, "Torso #:");
	rm_torso->align(FL_ALIGN_LEFT);

	Fl_Return_Button *rm_create = new Fl_Return_Button(425, 240, 120, 25, "Create");
	rm_create->callback((Fl_Callback *)create_modelCB, 0);

	Fl_Button *rm_cancel = new Fl_Button(560, 240, 60, 25, "Cancel");
	rm_cancel->callback((Fl_Callback *)cancel_modelCB, 0);

	models->end();
	models->show();
	models->set_non_modal();

	return(Fl::run());
}


//
// Robot Part Dialogs
//

class Model_Dialog {
public:
	Model_Dialog() {

		dialog = new Fl_Window(660, 500, "New Model");

		string AllParts = shoppe.all_parts();
		char *testing = new char[AllParts.length() + 1];
		strcpy(testing, AllParts.c_str());

		Fl_Text_Buffer *buff = new Fl_Text_Buffer();
		Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 340 - 40, 480 - 40, "Part Lists");
		disp->buffer(buff);
		
		buff->text(testing);



		rm_part_number = new Fl_Input(425, 30, 210, 25, "Part #:");
		rm_part_number->align(FL_ALIGN_LEFT);

		rm_name = new Fl_Input(425, 60, 210, 25, "Model Name:");
		rm_name->align(FL_ALIGN_LEFT);

		rm_head = new Fl_Input(425, 90, 210, 25, "Head #:");
		rm_head->align(FL_ALIGN_LEFT);

		rm_arm = new Fl_Input(425, 120, 210, 25, "Arm #:");
		rm_arm->align(FL_ALIGN_LEFT);

		rm_batt = new Fl_Input(425, 150, 210, 25, "Battery #:");
		rm_batt->align(FL_ALIGN_LEFT);

		rm_loco = new Fl_Input(425, 180, 210, 25, "Locomotor #:");
		rm_loco->align(FL_ALIGN_LEFT);

		rm_torso = new Fl_Input(425, 210, 210, 25, "Torso #:");
		rm_torso->align(FL_ALIGN_LEFT);

		rm_create = new Fl_Return_Button(425, 240, 120, 25, "Create");
		rm_create->callback((Fl_Callback *)create_modelCB, 0);

		rm_cancel = new Fl_Button(560, 240, 60, 25, "Cancel");
		rm_cancel->callback((Fl_Callback *)cancel_modelCB, 0);

		dialog->end();
		dialog->set_non_modal();
	}

	void show() { dialog->show(); }
	void hide() { dialog->hide(); }
	string part_number() { return rm_part_number->value(); }
	string name() { return rm_name->value(); }
	string head() { return rm_head->value(); }
	string arm() { return rm_arm->value(); }
	string batt() { return rm_batt->value(); }
	string loco() { return rm_loco->value(); }
	string torso() { return rm_torso->value(); }

private:
	Fl_Window *dialog;
	Fl_Input *rm_part_number;
	Fl_Input *rm_name;
	Fl_Input *rm_head;
	Fl_Input *rm_arm;
	Fl_Input *rm_batt;
	Fl_Input *rm_loco;
	Fl_Input *rm_torso;
	Fl_Return_Button *rm_create;
	Fl_Button *rm_cancel;

};


class Head_Dialog {
public:
	Head_Dialog() {

		dialog = new Fl_Window(340, 240, "Head");

		rp_part_number = new Fl_Input(120, 10, 210, 25, "Part Number:");
		rp_part_number->align(FL_ALIGN_LEFT);

		rp_quantity = new Fl_Input(120, 40, 210, 25, "Quantity:");
		rp_quantity->align(FL_ALIGN_LEFT);

		rp_weight = new Fl_Input(120, 70, 210, 25, "Weight:");
		rp_weight->align(FL_ALIGN_LEFT);

		rp_cost = new Fl_Input(120, 100, 210, 25, "Cost:");
		rp_cost->align(FL_ALIGN_LEFT);

		rp_description = new Fl_Multiline_Input(120, 130, 210, 75, "Description:");
		rp_description->align(FL_ALIGN_LEFT);

		rp_create = new Fl_Return_Button(145, 210, 120, 25, "Create");
		rp_create->callback((Fl_Callback *)create_headCB, 0);

		rp_cancel = new Fl_Button(270, 210, 60, 25, "Cancel");
		rp_cancel->callback((Fl_Callback *)cancel_headCB, 0);

		dialog->end();
		dialog->set_non_modal();
		}

		void show() { dialog->show(); }
		void hide() { dialog->hide(); }
		string part_number() { return rp_part_number->value(); }
		string weight() { return rp_weight->value(); }
		string cost() { return rp_cost->value(); }
		string description() { return rp_description->value(); }
		string quantity() { return rp_quantity->value(); }

		private:
		Fl_Window *dialog;
		Fl_Input *rp_part_number;
		Fl_Input *rp_weight;
		Fl_Input *rp_cost;
		Fl_Input *rp_description;
		Fl_Return_Button *rp_create;
		Fl_Button *rp_cancel;

		Fl_Input *rp_quantity;
		};

class Arm_Dialog {
public:
	Arm_Dialog() {

		dialog = new Fl_Window(340, 270, "Arm");

		rp_part_number = new Fl_Input(120, 10, 210, 25, "Part Number:");
		rp_part_number->align(FL_ALIGN_LEFT);

		rp_quantity = new Fl_Input(120, 40, 210, 25, "Quantity:");
		rp_quantity->align(FL_ALIGN_LEFT);

		rp_weight = new Fl_Input(120, 70, 210, 25, "Weight:");
		rp_weight->align(FL_ALIGN_LEFT);

		rp_cost = new Fl_Input(120, 100, 210, 25, "Cost:");
		rp_cost->align(FL_ALIGN_LEFT);

		rp_power = new Fl_Input(120, 130, 210, 25, "Power:");
		rp_power->align(FL_ALIGN_LEFT);

		rp_description = new Fl_Multiline_Input(120, 160, 210, 75, "Description:");
		rp_description->align(FL_ALIGN_LEFT);
	
		rp_create = new Fl_Return_Button(145, 240, 120, 25, "Create");
		rp_create->callback((Fl_Callback *)create_armCB, 0);

		rp_cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
		rp_cancel->callback((Fl_Callback *)cancel_armCB, 0);

		dialog->end();
		dialog->set_non_modal();
		}

		void show() { dialog->show(); }
		void hide() { dialog->hide(); }
		void redraw() { dialog->redraw(); }
		string part_number() { return rp_part_number->value(); }
		string weight() { return rp_weight->value(); }
		string cost() { return rp_cost->value(); }
		string description() { return rp_description->value(); }
		string power() { return rp_power->value(); }
		string quantity() { return rp_quantity->value(); }

		private:
		Fl_Window *dialog;
		Fl_Input *rp_part_number;
		Fl_Input *rp_weight;
		Fl_Input *rp_cost;
		Fl_Input *rp_description;
		Fl_Return_Button *rp_create;
		Fl_Button *rp_cancel;

		Fl_Input *rp_quantity;
		Fl_Input *rp_power;
		};

class Battery_Dialog {
public:
	Battery_Dialog() {

		dialog = new Fl_Window(340, 270, "Battery");

		rp_part_number = new Fl_Input(120, 10, 210, 25, "Part Number:");
		rp_part_number->align(FL_ALIGN_LEFT);

		rp_quantity = new Fl_Input(120, 40, 210, 25, "Quantity:");
		rp_quantity->align(FL_ALIGN_LEFT);

		rp_weight = new Fl_Input(120, 70, 210, 25, "Weight:");
		rp_weight->align(FL_ALIGN_LEFT);

		rp_cost = new Fl_Input(120, 100, 210, 25, "Cost:");
		rp_cost->align(FL_ALIGN_LEFT);

		rp_energy = new Fl_Input(120, 130, 210, 25, "Energy:");
		rp_energy->align(FL_ALIGN_LEFT);

		rp_description = new Fl_Multiline_Input(120, 160, 210, 75, "Description:");
		rp_description->align(FL_ALIGN_LEFT);
	
		rp_create = new Fl_Return_Button(145, 240, 120, 25, "Create");
		rp_create->callback((Fl_Callback *)create_battCB, 0);

		rp_cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
		rp_cancel->callback((Fl_Callback *)cancel_battCB, 0);

		dialog->end();
		dialog->set_non_modal();
		}

		void show() { dialog->show(); }
		void hide() { dialog->hide(); }
		string part_number() { return rp_part_number->value(); }
		string weight() { return rp_weight->value(); }
		string cost() { return rp_cost->value(); }
		string description() { return rp_description->value(); }
		string energy() { return rp_energy->value(); }
		string quantity() { return rp_quantity->value(); }

		private:
		Fl_Window *dialog;
		Fl_Input *rp_part_number;
		Fl_Input *rp_weight;
		Fl_Input *rp_cost;
		Fl_Input *rp_description;
		Fl_Return_Button *rp_create;
		Fl_Button *rp_cancel;

		Fl_Input *rp_quantity;
		Fl_Input *rp_energy;
		};

class Locomotor_Dialog {
public:
	Locomotor_Dialog() {


		dialog = new Fl_Window(340, 300, "Locomotor");

		rp_part_number = new Fl_Input(120, 10, 210, 25, "Part Number:");
		rp_part_number->align(FL_ALIGN_LEFT);

		rp_quantity = new Fl_Input(120, 40, 210, 25, "Quantity:");
		rp_quantity->align(FL_ALIGN_LEFT);

		rp_weight = new Fl_Input(120, 70, 210, 25, "Weight:");
		rp_weight->align(FL_ALIGN_LEFT);

		rp_cost = new Fl_Input(120, 100, 210, 25, "Cost:");
		rp_cost->align(FL_ALIGN_LEFT);

		rp_power = new Fl_Input(120, 130, 210, 25, "Power:");
		rp_power->align(FL_ALIGN_LEFT);

		rp_speed = new Fl_Input(120, 160, 210, 25, "Maximum Speed:");
		rp_speed->align(FL_ALIGN_LEFT);

		rp_description = new Fl_Multiline_Input(120, 190, 210, 75, "Description:");
		rp_description->align(FL_ALIGN_LEFT);
	
		rp_create = new Fl_Return_Button(145, 270, 120, 25, "Create");
		rp_create->callback((Fl_Callback *)create_locoCB, 0);

		rp_cancel = new Fl_Button(270, 270, 60, 25, "Cancel");
		rp_cancel->callback((Fl_Callback *)cancel_locoCB, 0);

		dialog->end();
		dialog->set_non_modal();
		}

		void show() { dialog->show(); }
		void hide() { dialog->hide(); }
		string part_number() { return rp_part_number->value(); }
		string weight() { return rp_weight->value(); }
		string cost() { return rp_cost->value(); }
		string description() { return rp_description->value(); }
		string power() { return rp_power->value(); }
		string speed() { return rp_speed->value(); }
		string quantity() { return rp_quantity->value(); }

		private:
		Fl_Window *dialog;
		Fl_Input *rp_part_number;
		Fl_Input *rp_weight;
		Fl_Input *rp_cost;
		Fl_Input *rp_description;
		Fl_Return_Button *rp_create;
		Fl_Button *rp_cancel;

		Fl_Input *rp_quantity;
		Fl_Input *rp_power;
		Fl_Input *rp_speed;
		};

class Torso_Dialog {
public:
	Torso_Dialog() {

		dialog = new Fl_Window(340, 270, "Torso");

		rp_part_number = new Fl_Input(120, 10, 210, 25, "Part Number:");
		rp_part_number->align(FL_ALIGN_LEFT);

		rp_quantity = new Fl_Input(120, 40, 210, 25, "Quantity:");
		rp_quantity->align(FL_ALIGN_LEFT);

		rp_weight = new Fl_Input(120, 70, 210, 25, "Weight:");
		rp_weight->align(FL_ALIGN_LEFT);

		rp_cost = new Fl_Input(120, 100, 210, 25, "Cost:");
		rp_cost->align(FL_ALIGN_LEFT);

		rp_batt_count = new Fl_Input(120, 130, 210, 25, "Battery Count:");
		rp_batt_count->align(FL_ALIGN_LEFT);

		rp_description = new Fl_Multiline_Input(120, 160, 210, 75, "Description:");
		rp_description->align(FL_ALIGN_LEFT);
	
		rp_create = new Fl_Return_Button(145, 240, 120, 25, "Create");
		rp_create->callback((Fl_Callback *)create_torsoCB, 0);

		rp_cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
		rp_cancel->callback((Fl_Callback *)cancel_torsoCB, 0);

		dialog->end();
		dialog->set_non_modal();
		}

		void show() { dialog->show(); }
		void hide() { dialog->hide(); }
		string part_number() { return rp_part_number->value(); }
		string weight() { return rp_weight->value(); }
		string cost() { return rp_cost->value(); }
		string description() { return rp_description->value(); }
		string batt_count() { return rp_batt_count->value(); }
		string quantity() { return rp_quantity->value(); }

		private:
		Fl_Window *dialog;
		Fl_Input *rp_part_number;
		Fl_Input *rp_weight;
		Fl_Input *rp_cost;
		Fl_Input *rp_description;
		Fl_Return_Button *rp_create;
		Fl_Button *rp_cancel;

		Fl_Input *rp_quantity;
		Fl_Input *rp_batt_count;
		};


// Customer Dialog
class Customer_Dialog {
public:
	Customer_Dialog() {

		dialog = new Fl_Window(340, 150, "Customer");

		c_name = new Fl_Input(120, 10, 210, 25, "Name:");
		c_name->align(FL_ALIGN_LEFT);

		c_num = new Fl_Input(120, 40, 210, 25, "Number:");
		c_num->align(FL_ALIGN_LEFT);

		sa_num = new Fl_Input(120, 70, 210, 25, "Sales Associate\nNumber:");
		sa_num->align(FL_ALIGN_LEFT);

		c_create = new Fl_Return_Button(145, 120, 120, 25, "Create");
		c_create->callback((Fl_Callback *)create_custCB, 0);

		c_cancel = new Fl_Button(270, 120, 60, 25, "Cancel");
		c_cancel->callback((Fl_Callback *)cancel_custCB, 0);

		dialog->end();
		dialog->set_non_modal();
	}

	void show() { dialog->show(); }
	void hide() { dialog->hide(); }
	string cust_name() { return c_name->value(); }
	string cust_number() { return c_num->value(); }
	string sa_number() { return sa_num->value(); }

private:
	Fl_Window *dialog;
	Fl_Input *c_name;
	Fl_Input *c_num;
	Fl_Input *sa_num;

	Fl_Return_Button *c_create;
	Fl_Button *c_cancel;
};

// Sales Associate Dialog
class SalesAssociate_Dialog {
public:
	SalesAssociate_Dialog() {

		dialog = new Fl_Window(340, 130, "Sales Associate");

		sa_name = new Fl_Input(120, 10, 210, 25, "Name:");
		sa_name->align(FL_ALIGN_LEFT);

		sa_num = new Fl_Input(120, 40, 210, 25, "Number:");
		sa_num->align(FL_ALIGN_LEFT);

		sa_create = new Fl_Return_Button(145, 100, 120, 25, "Create");
		sa_create->callback((Fl_Callback *)create_saCB, 0);

		sa_cancel = new Fl_Button(270, 100, 60, 25, "Cancel");
		sa_cancel->callback((Fl_Callback *)cancel_saCB, 0);

		dialog->end();
		dialog->set_non_modal();
	}

	void show() { dialog->show(); }
	void hide() { dialog->hide(); }
	string SA_name() { return sa_name->value(); }
	string sa_number() { return sa_num->value(); }

private:
	Fl_Window *dialog;
	Fl_Input *sa_name;
	Fl_Input *sa_num;

	Fl_Return_Button *sa_create;
	Fl_Button *sa_cancel;
};


//
// Callbacks
//
int sa_View(Fl_Widget* w, void* p) {
	const int X = 800;
	const int Y = 600;
	const int border = 10;

	saReports = new Fl_Window{ X, Y, "Robot Shoppe" };
	view = new View{ 0, 0, X, Y };

	// Sign up for callback
	//test->callback(CloseCB, view);
	// Enable resizing
	saReports->resizable(*view);

	//Turn string into Char array
	string AllSa = shoppe.list_sa();
	char *testing = new char[AllSa.length() + 1];
	strcpy(testing, AllSa.c_str());

	Fl_Text_Buffer *buff = new Fl_Text_Buffer();
	Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 640 - 40, 480 - 40, "Sales Associate List");
	disp->buffer(buff);
	win->resizable(*disp);
	win->show();
	buff->text(testing);

	// Wrap it up and let FLTK do its thing
	saReports->end();
	saReports->show();
	return(Fl::run());
}

int customer_View(Fl_Widget* w, void* p) {
	const int X = 800;
	const int Y = 600;
	const int border = 10;
	
	custReports = new Fl_Window{ X, Y, "Robot Shoppe" };
	view = new View{ 0, 0, X, Y };

	// Sign up for callback
	//test->callback(CloseCB, view);
	// Enable resizing
	custReports->resizable(*view);
	
	//Turn string into Char array
	string AllCusts = shoppe.list_cust();
	char *testing = new char[AllCusts.length() + 1];
	strcpy(testing, AllCusts.c_str());

	Fl_Text_Buffer *buff = new Fl_Text_Buffer();
	Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 640 - 40, 480 - 40, "Customer List");
	disp->buffer(buff);
	win->resizable(*disp);
	win->show();
	buff->text(testing);
	
	// Wrap it up and let FLTK do its thing
	custReports->end();
	custReports->show();
	return(Fl::run());
}

void CloseCB(Fl_Widget* w, void* p) {
	int selection = 1;
	if (!view->saved()) {
		selection = fl_choice("Unsaved shoppe. Exit anyway?", fl_no, fl_yes, 0);
	}
	if (selection == 1) {
		win->hide();
	}
}

// menu create callback functions
void menu_create_modelCB(Fl_Widget* w, void* p) {
	createModel(w, p);
	
	//model_dlg->show();
}
void menu_create_headCB(Fl_Widget* w, void* p) {
	head_dlg->show();
}
void menu_create_armCB(Fl_Widget* w, void* p) {
	arm_dlg->show();
}
void menu_create_battCB(Fl_Widget* w, void* p) {
	batt_dlg->show();
}
void menu_create_locoCB(Fl_Widget* w, void* p) {
	loco_dlg->show();
}
void menu_create_torsoCB(Fl_Widget* w, void* p) {
	torso_dlg->show();
}

void menu_create_custCB(Fl_Widget* w, void* p) {
	cust_dlg->show();
}
void menu_create_saCB(Fl_Widget* w, void* p) {
	sa_dlg->show();
}
// cancel callback functions
void cancel_headCB(Fl_Widget* w, void* p) {
	head_dlg->hide();
}
void cancel_armCB(Fl_Widget* w, void* p) {
	arm_dlg->hide();
}
void cancel_battCB(Fl_Widget* w, void* p) {
	batt_dlg->hide();
}
void cancel_locoCB(Fl_Widget* w, void* p) {
	loco_dlg->hide();
}
void cancel_torsoCB(Fl_Widget* w, void* p) {
	torso_dlg->hide();
}

void cancel_modelCB(Fl_Widget* w, void* p) {
	models->hide();
}

void cancel_custCB(Fl_Widget* w, void* p) {
	cust_dlg->hide();
}
void cancel_saCB(Fl_Widget* w, void* p) {
	sa_dlg->hide();
}
// create callback functions
void create_headCB(Fl_Widget* w, void* p) {

	int weight = stoi(head_dlg->weight());
	int cost = stoi(head_dlg->cost());
	int quantity = stoi(head_dlg->quantity());

	shoppe.create_newpart(new Head(head_dlg->part_number(), weight, cost, head_dlg->description(), quantity), 1);

	head_dlg->hide();
}


void create_modelCB(Fl_Widget* w, void* p) {

	int head = stoi(rm_head->value());
	int arm = stoi(rm_arm->value());
	int batt = stoi(rm_batt->value());
	int loco = stoi(rm_loco->value());
	int torso = stoi(rm_torso->value());

	shoppe.make_model(head-1, arm-1, batt-1, loco-1, torso-1, rm_part_number->value(), rm_name->value());

	models->hide();
}

void create_armCB(Fl_Widget* w, void* p) {

	
	
	int weight = stoi(arm_dlg->weight());
	int cost = stoi(arm_dlg->cost());
	int quantity = stoi(arm_dlg->quantity());
	int power = stoi(arm_dlg->power());

	shoppe.create_newpart(new Arm(arm_dlg->part_number(), weight, cost, arm_dlg->description(), power, quantity), 2);
	arm_dlg->hide();
}
void create_battCB(Fl_Widget* w, void* p) {

	int weight = stoi(batt_dlg->weight());
	int cost = stoi(batt_dlg->cost());
	int quantity = stoi(batt_dlg->quantity());
	int energy = stoi(batt_dlg->energy());

	shoppe.create_newpart(new Battery(batt_dlg->part_number(), weight, cost, batt_dlg->description(), energy, quantity), 3);

	batt_dlg->hide();
}
void create_locoCB(Fl_Widget* w, void* p) {

	int weight = stoi(loco_dlg->weight());
	int cost = stoi(loco_dlg->cost());
	int quantity = stoi(loco_dlg->quantity());
	int power = stoi(loco_dlg->power());
	int speed = stoi(loco_dlg->speed());

	shoppe.create_newpart(new Locomotor(loco_dlg->part_number(), weight, cost, loco_dlg->description(), power, speed, quantity), 4);

	loco_dlg->hide();
}
void create_torsoCB(Fl_Widget* w, void* p) {

	int weight = stoi(torso_dlg->weight());
	int cost = stoi(torso_dlg->cost());
	int quantity = stoi(torso_dlg->quantity());
	int batt_count = stoi(torso_dlg->batt_count());

	shoppe.create_newpart(new Torso(torso_dlg->part_number(), weight, cost, torso_dlg->description(), batt_count, quantity), 5);

	torso_dlg->hide();
}


void create_custCB(Fl_Widget* w, void* p) {

	shoppe.add_customer(new Customer(cust_dlg->cust_name(), cust_dlg->cust_number(), cust_dlg->sa_number()));

	cust_dlg->hide();

}

void create_saCB(Fl_Widget* w, void* p) {


	shoppe.add_sa(new SalesAssociate(sa_dlg->SA_name(), sa_dlg->sa_number()));

	sa_dlg->hide();

}

void SaveCB(Fl_Widget* w, void* p) {
	int selection = 1;
	if (!view->dataDownload()) {
		selection = fl_choice("Are you sure you want to save the shoppe data?", fl_no, fl_yes, 0);
	}
	if (selection == 1) {
		shoppe.save_info();
	}
}

void SaveAsCB(Fl_Widget* w, void* p) {
	int selection = 1;
	string t1 = string{ fl_input("Enter a filename with extension.", 0) };
	
	if (selection == 1) {
		shoppe.save_as_info(t1);
	}
}

void loadCB(Fl_Widget* w, void* p) {
	int selection = 1;
	if (!view->dataDownload()) {
		selection = fl_choice("Are you sure you want to load the shoppe data?", fl_no, fl_yes, 0);
	}
	if (selection == 1) {
		load_choice_data("data.txt");
	}
}

void loadchooseCB(Fl_Widget* w, void* p) {
	int selection = 1;
	string t1 = string{ fl_input("Enter the filename with extension to load.", 0) };

	if (selection == 1) {
		load_choice_data(t1);
	}
}



//
// Menu
//

Fl_Menu_Item menuitems[] = {
{ "&File", 0, 0, 0, FL_SUBMENU },
	{"&Open Default", FL_ALT + 'o', (Fl_Callback *)loadCB},
	{ "&Open Other", 0, (Fl_Callback *)loadchooseCB },
	{"&Save to Default", FL_ALT + 's', (Fl_Callback *)SaveCB },
	{ "&Save to New", 0, (Fl_Callback *)SaveAsCB },
	{ "&Quit", FL_ALT + 'q', (Fl_Callback *)CloseCB },
	{ 0 },

{ "&Edit", 0, 0, 0, FL_SUBMENU },
	{ "&Undo", FL_ALT + 'z' },
	{ "&Cut", FL_ALT + 'x' },
	{ "&Copy", FL_ALT + 'c' },
	{ "&Paste", FL_ALT + 'v' },
	{ 0 },

{ "&Create", 0, 0, 0, FL_SUBMENU },
	{ "Order", 0,(Fl_Callback *)createOrder,0,FL_MENU_DIVIDER },
	{ "Customer", 0, (Fl_Callback *)menu_create_custCB },
	{ "Sales Associate", 0,(Fl_Callback *)menu_create_saCB,0,FL_MENU_DIVIDER },
	{ "&Robot Part", 0, 0, 0, FL_SUBMENU},
		{ "Robot Head", 0, (Fl_Callback *)menu_create_headCB },
		{ "Robot Arm", 0, (Fl_Callback *)menu_create_armCB},
		{ "Robot Battery", 0, (Fl_Callback *)menu_create_battCB },
		{ "Robot Locomotor", 0, (Fl_Callback *)menu_create_locoCB },
		{ "Robot Torso", 0, (Fl_Callback *)menu_create_torsoCB },
		{ 0 },
	{ "Robot Model", 0, (Fl_Callback *)menu_create_modelCB },
	{ 0 },

{ "&Report", 0, 0, 0, FL_SUBMENU },
	{ "Invoice", 0,0,0,FL_MENU_DIVIDER },
	{ "All Orders" },
	{ "Orders by Customer" },
	{ "Orders by Sales Associate", 0,0,0,FL_MENU_DIVIDER },
	{ "All Customers", 0, (Fl_Callback *)customer_View},
	{ "All Sales Associates" , 0,(Fl_Callback *)sa_View,0,FL_MENU_DIVIDER },
	{ "All Robot Models", 0, (Fl_Callback *)showCatalog },
	{ "All Robot Parts" },
	{ 0 },

{ "&Login", 0, 0, 0, FL_SUBMENU },
	{ "As Product Manager" },
	{ "As Beloved Customer" },
	{ "As Sales Associate" },
	{ "As Pointed-Haired Boss" },
	{ 0 },

{ "&Help", 0, 0, 0, FL_SUBMENU },
	{ "&Manual" },
	{ "&About" },
	{ 0 },
};

//
// Main
//
int main() {
	
	const int X = 800;
	const int Y = 600;
	const int border = 10;

	// Create dialogs
	head_dlg = new Head_Dialog{};
	arm_dlg = new Arm_Dialog{};
	batt_dlg = new Battery_Dialog{};
	loco_dlg = new Locomotor_Dialog{};
	torso_dlg = new Torso_Dialog{};
	cust_dlg = new Customer_Dialog{};
	sa_dlg = new SalesAssociate_Dialog{};
	model_dlg = new Model_Dialog{};

	// Create a window and box
	win = new Fl_Window{ X, Y, "Robot Shoppe" };
	

	jpgbox = new Fl_Box(250, 250, 300, 100);
	weljpg = new Fl_JPEG_Image("welcome_screen.jpg");
	jpgbox->image(weljpg);


	// Install menu bar
	menubar = new Fl_Menu_Bar(0, 0, X, 30);
	menubar->menu(menuitems);
	// Create a view (a canvas on which to draw)
	view = new View{ 0, 0, X, Y };
	// Sign up for callback
	win->callback(CloseCB, view);
	// Enable resizing
	win->resizable(*view);

	// Wrap it up and let FLTK do its thing
	win->end();
	win->show();
	return(Fl::run());
}

