#include "locomotor.h"
#include <stdio.h>
#include <fstream>
#include <ostream>

void Locomotor:: save_all() {

    ofstream ofs;
    ofs.open("data.txt", ofstream::out | ofstream::app);

            ofs << p_num << endl;
            ofs << p_weight << endl;
            ofs << p_cost << endl;
            ofs << p_quantity << endl;
            ofs << p_power << endl;
            ofs << p_maxspeed << endl;
            ofs << p_description << endl;

            ofs.close();
}
