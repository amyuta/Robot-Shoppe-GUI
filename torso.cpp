
#include <stdio.h>
#include <ostream>
#include <fstream>
#include "torso.h"

int Torso::quan_count(){
    
    return p_battcount;
    
}

void Torso:: save_all() {

    ofstream ofs;
    ofs.open("data.txt", ofstream::out | ofstream::app);

            ofs << p_num << endl;
            ofs << p_weight << endl;
            ofs << p_cost << endl;
            ofs << p_quantity << endl;
            ofs << p_battcount << endl;
            ofs << p_description << endl;

            ofs.close();
}

