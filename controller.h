#ifndef __CONTROLLER_H
#define __CONTROLLER_H

#include "view.h"
#include "shoppe.h"

class Controller {
public:
	Controller(Shoppe& shop) : shoppe(shop) { }
	void cli();
	void execute_cmd(int cmd);
	void create_model();
	void new_customer();
    void new_sa();
	void place_order(int model, string name, int num, int sales_a);
    void make_order();
    void show_order();
    void list_orders();
    void sa_raise();
    void pb_raise();
    void sales_report();
	void execute_createnewpart(int cmd);
    void execute_createrobotmodel();
    void execute_showrobotmodels();
    void load_data();
private:
	Shoppe& shoppe;
	View view;
	
};
#endif
#pragma once
