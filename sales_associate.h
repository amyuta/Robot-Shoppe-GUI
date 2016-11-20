#ifndef SALES_ASSOCIATE_H
#define SALES_ASSOCIATE_H

#include <string>
using namespace std;

class SalesAssociate {

public:
    SalesAssociate(string sa_name, string sa_num) : name(sa_name), number(sa_num) {}
    void save_all();
	void save_as_all(string filename);
    string get_info();
    void raisecheck();
    void raise_final();
	int get_SaNum();
    
private:
    string name;
    string number;
    bool raise_check = false;
    bool raise = false;

};

#endif // SALES_ASSOCIATE_H
