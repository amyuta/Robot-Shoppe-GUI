#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Text_Display.H>
#include <FL/fl_ask.H>
#include <Fl/Fl_PNG_Image.H>
#include <Fl/Fl_JPEG_Image.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Return_Button.H>

#include <iostream>
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


class Robot_Part_Dialog;
class Head_Dialog;
class Arm_Dialog;
class Battery_Dialog;
class Locomotor_Dialog;
class Torso_Dialog;

//
// Widgets
//
Fl_Window *win;
Fl_Menu_Bar *menubar;
Fl_Box *box;
Fl_Input *t1, *t2, *t3, *t4, *t5, *t6, *t7;
View *view;
Fl_Box *jpgbox;
Fl_JPEG_Image *weljpg;
Robot_Part_Dialog *rp_dlg;
Head_Dialog *head_dlg;
Arm_Dialog *arm_dlg;
Battery_Dialog *batt_dlg;
Locomotor_Dialog *loco_dlg;
Torso_Dialog *torso_dlg;

//
// Robot Part Dialogs
//
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

//
// Callbacks
//
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

// create callback functions
void create_headCB(Fl_Widget* w, void* p) {

	Shoppe shoppe;
	int part_num = stoi(head_dlg->part_number());
	int weight = stoi(head_dlg->weight());
	int cost = stoi(head_dlg->cost());
	int quantity = stoi(head_dlg->quantity());

	shoppe.create_newpart(new Head(part_num, weight, cost, head_dlg->description(), quantity), 1);

	head_dlg->hide();
}
void create_armCB(Fl_Widget* w, void* p) {

	Shoppe shoppe;
	int part_num = stoi(arm_dlg->part_number());
	int weight = stoi(arm_dlg->weight());
	int cost = stoi(arm_dlg->cost());
	int quantity = stoi(arm_dlg->quantity());
	int power = stoi(arm_dlg->power());

	shoppe.create_newpart(new Arm(part_num, weight, cost, arm_dlg->description(), power, quantity), 2);

	arm_dlg->hide();
}
void create_battCB(Fl_Widget* w, void* p) {

	Shoppe shoppe;
	int part_num = stoi(batt_dlg->part_number());
	int weight = stoi(batt_dlg->weight());
	int cost = stoi(batt_dlg->cost());
	int quantity = stoi(batt_dlg->quantity());
	int energy = stoi(batt_dlg->energy());

	shoppe.create_newpart(new Battery(part_num, weight, cost, batt_dlg->description(), energy, quantity), 3);

	batt_dlg->hide();
}
void create_locoCB(Fl_Widget* w, void* p) {

	Shoppe shoppe;
	int part_num = stoi(loco_dlg->part_number());
	int weight = stoi(loco_dlg->weight());
	int cost = stoi(loco_dlg->cost());
	int quantity = stoi(loco_dlg->quantity());
	int power = stoi(loco_dlg->power());
	int speed = stoi(loco_dlg->speed());

	shoppe.create_newpart(new Locomotor(part_num, weight, cost, loco_dlg->description(), power, speed, quantity), 4);

	loco_dlg->hide();
}
void create_torsoCB(Fl_Widget* w, void* p) {

	Shoppe shoppe;
	int part_num = stoi(torso_dlg->part_number());
	int weight = stoi(torso_dlg->weight());
	int cost = stoi(torso_dlg->cost());
	int quantity = stoi(torso_dlg->quantity());
	int batt_count = stoi(torso_dlg->batt_count());

	shoppe.create_newpart(new Torso(part_num, weight, cost, torso_dlg->description(), batt_count, quantity), 5);

	torso_dlg->hide();
}


//...
void createcust(Fl_Widget* w, void* p) {

	Shoppe shoppe;

	string t1 = string{ fl_input("Enter the customer's name.", 0) };
	string t2 = string{ fl_input("Enter the customer's number.", 0) };
	string t3 = string{ fl_input("Enter a sales associate's number.", 0) };


	int c_num = stoi(t2);
	int s_num = stoi(t3);
	shoppe.add_customer(new Customer(t1, c_num, s_num));


	//shoppe.create_newpart(new Head(part_num, weight, cost, t5, quantity), 1);

}

void createsa(Fl_Widget* w, void* p) {

	Shoppe shoppe;

	string t1 = string{ fl_input("Enter the sales associate's name.", 0) };
	string t2 = string{ fl_input("Enter the sales associate's number.", 0) };


	int sa_num = stoi(t2);
	shoppe.add_sa(new SalesAssociate(t1, sa_num));


	//shoppe.create_newpart(new Head(part_num, weight, cost, t5, quantity), 1);

}


//
// Menu
//
Fl_Menu_Item menuitems[] = {
{ "&File", 0, 0, 0, FL_SUBMENU },
	{"&New", FL_ALT + 'n'},
	{"&Open", FL_ALT + 'o'},
	{"&Save", FL_ALT + 's' },
	{ "&Quit", FL_ALT + 'q', (Fl_Callback *)CloseCB },
	{ 0 },

{ "&Edit", 0, 0, 0, FL_SUBMENU },
	{ "&Undo", FL_ALT + 'z' },
	{ "&Cut", FL_ALT + 'x' },
	{ "&Copy", FL_ALT + 'c' },
	{ "&Paste", FL_ALT + 'v' },
	{ 0 },

{ "&Create", 0, 0, 0, FL_SUBMENU },
	{ "Order", 0,0,0,FL_MENU_DIVIDER },
	{ "Customer", 0, (Fl_Callback *)createcust },
	{ "Sales Associate", 0,(Fl_Callback *)createsa,0,FL_MENU_DIVIDER },
	{ "&Robot Part", 0, 0, 0, FL_SUBMENU},
		{ "Robot Head", 0, (Fl_Callback *)menu_create_headCB },
		{ "Robot Arm", 0, (Fl_Callback *)menu_create_armCB},
		{ "Robot Battery", 0, (Fl_Callback *)menu_create_battCB },
		{ "Robot Locomotor", 0, (Fl_Callback *)menu_create_locoCB },
		{ "Robot Torso", 0, (Fl_Callback *)menu_create_torsoCB },
		{ 0 },
	{ "Robot Model" },
	{ 0 },

{ "&Report", 0, 0, 0, FL_SUBMENU },
	{ "Invoice", 0,0,0,FL_MENU_DIVIDER },
	{ "All Orders" },
	{ "Orders by Customer" },
	{ "Orders by Sales Associate", 0,0,0,FL_MENU_DIVIDER },
	{ "All Customers" },
	{ "All Sales Associates" , 0,0,0,FL_MENU_DIVIDER },
	{ "All Robot Models" },
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
	Shoppe shoppe;
	const int X = 800;
	const int Y = 600;
	const int border = 10;

	// Create dialogs
	head_dlg = new Head_Dialog{};
	arm_dlg = new Arm_Dialog{};
	batt_dlg = new Battery_Dialog{};
	loco_dlg = new Locomotor_Dialog{};
	torso_dlg = new Torso_Dialog{};

	// Create a window and box
	win = new Fl_Window{ X, Y, "Robot Shoppe" };
	/*box = new Fl_Box(100, 150, 300, 100, "Welcome to the\nRobot Shoppe!");
	box->box(FL_UP_BOX);
	box->labelfont(FL_BOLD + FL_ITALIC);
	box->labelsize(36);
	box->labeltype(FL_SHADOW_LABEL);
	*/


	//upload welcome_screen image

	/*pngbox = new Fl_Box(100, 150, 600, 500);
	welpng = new Fl_PNG_Image("welcome_screen.png");
	pngbox->image(welpng);
	*/

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