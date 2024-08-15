#include <iostream>
#include <string>
#include "Student.h"
#include "Course.h"
#include "SchoolManagerSystem.h"
using namespace std;
using namespace PA4;

namespace PA4
{
Student::Student(){	c_refe = new Course[++(c_size)];	}
void Student::take_student(){
	SchoolManagerSystem system;
        cin.ignore();
        string select_1_name, select_1_id;
        cout<<"Enter a student name and ID: ";
        getline(cin, select_1_name);
        select_1_id = system.parseString(select_1_name);
    //    cout <<select_1_name<<"--"<<select_1_id<<endl;
        int id_int= stoi(select_1_id);
        name=select_1_name;
        id=id_int;
}
}
