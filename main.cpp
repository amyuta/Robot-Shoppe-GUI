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
// Widgets
//
Fl_Window *win;
Fl_Menu_Bar *menubar;
Fl_Box *box;
Fl_Input *t1, *t2, *t3, *t4, *t5, *t6, *t7;
View *view;
//Fl_Box *pngbox;
//Fl_PNG_Image *welpng;
Fl_Box *jpgbox;
Fl_JPEG_Image *weljpg;


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

void createcust(Fl_Widget* w, void* p) {

	Shoppe shoppe;

	string t1 = string{ fl_input("Enter the customer's name.", 0) };
	string t2 = string{ fl_input("Enter the customer's number.", 0) };
	string t3 = string{ fl_input("Enter a sales associate's number.", 0) };

	 
	int c_num = stoi(t2);
	int s_num = stoi(t3);
	shoppe.add_customer(new Customer(t1,c_num,s_num));


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

void headbox(Fl_Widget* w, void* p) {

	Shoppe shoppe;
	
	string t1 = string{fl_input("Enter the head's part number.", 0)};
	string t2 = string{ fl_input("Enter the head's weight.", 0) };
	string t3 = string{ fl_input("Enter the head's cost.", 0) };
	string t4 = string{ fl_input("Enter the head's quantity.", 0) };
	string t5 = string{ fl_input("Enter the head's description.", 0) };

	int part_num = stoi(t1);
	int weight = stoi(t2);
	int cost = stoi(t3);
	int quantity = stoi(t4);

	shoppe.create_newpart(new Head(part_num, weight, cost, t5, quantity), 1);

}

void armbox(Fl_Widget* w, void* p) {

	Shoppe shoppe;

	string t1 = string{ fl_input("Enter the arm's part number.", 0) };
	string t2 = string{ fl_input("Enter the arm's weight.", 0) };
	string t3 = string{ fl_input("Enter the arm's cost.", 0) };
	string t4 = string{ fl_input("Enter the arm's quantity.", 0) };
	string t5 = string{ fl_input("Enter the arm's power.", 0) };
	string t6 = string{ fl_input("Enter the arm's description.", 0) };

	int part_num = stoi(t1);
	int weight = stoi(t2);
	int cost = stoi(t3);
	int quantity = stoi(t4);
	int power = stoi(t5);

	shoppe.create_newpart(new Arm(part_num, weight, cost, t6, power, quantity), 2);
}

void battbox(Fl_Widget* w, void* p) {

	Shoppe shoppe;

	string t1 = string{ fl_input("Enter the battery's part number.", 0) };
	string t2 = string{ fl_input("Enter the battery's weight.", 0) };
	string t3 = string{ fl_input("Enter the battery's cost.", 0) };
	string t4 = string{ fl_input("Enter the battery's quantity.", 0) };
	string t5 = string{ fl_input("Enter the battery's energy.", 0) };
	string t6 = string{ fl_input("Enter the battery's description.", 0) };

	int part_num = stoi(t1);
	int weight = stoi(t2);
	int cost = stoi(t3);
	int quantity = stoi(t4);
	int energy = stoi(t5);

	shoppe.create_newpart(new Battery(part_num, weight, cost, t6, energy, quantity), 3);
}

void locobox(Fl_Widget* w, void* p) {

	Shoppe shoppe;

	string t1 = string{ fl_input("Enter the locomotor's part number.", 0) };
	string t2 = string{ fl_input("Enter the locomotor's weight.", 0) };
	string t3 = string{ fl_input("Enter the locomotor's cost.", 0) };
	string t4 = string{ fl_input("Enter the locomotor's quantity.", 0) };
	string t5 = string{ fl_input("Enter the locomotor's power.", 0) };
	string t6 = string{ fl_input("Enter the locomotor's max speed.", 0) };
	string t7 = string{ fl_input("Enter the locomotor's description.", 0) };

	int part_num = stoi(t1);
	int weight = stoi(t2);
	int cost = stoi(t3);
	int quantity = stoi(t4);
	int power = stoi(t5);
	int max_speed = stoi(t6);

	shoppe.create_newpart(new Locomotor(part_num, weight, cost, t5, power, max_speed, quantity), 4);
}

void torsobox(Fl_Widget* w, void* p) {

	Shoppe shoppe;

	string t1 = string{ fl_input("Enter the torso's part number.", 0) };
	string t2 = string{ fl_input("Enter the torso's weight.", 0) };
	string t3 = string{ fl_input("Enter the torso's cost.", 0) };
	string t4 = string{ fl_input("Enter the torso's quantity.", 0) };
	string t5 = string{ fl_input("Enter the torso's battery count.", 0) };
	string t6 = string{ fl_input("Enter the torso's description.", 0) };

	int part_num = stoi(t1);
	int weight = stoi(t2);
	int cost = stoi(t3);
	int quantity = stoi(t4);
	int batt_count = stoi(t5);
	int max_speed = stoi(t6);

	shoppe.create_newpart(new Torso(part_num, weight, cost, t6, batt_count, quantity), 5);
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
		{ "Robot Arm", 0, (Fl_Callback *)armbox },
		{ "Robot Battery", 0, (Fl_Callback *)battbox },
		{ "Robot Head", 0, (Fl_Callback *)headbox },
		{ "Robot Locomotor", 0, (Fl_Callback *)locobox },
		{ "Robot Torso", 0, (Fl_Callback *)torsobox },
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