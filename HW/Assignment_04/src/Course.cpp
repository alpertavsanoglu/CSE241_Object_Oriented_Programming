#include <iostream>
#include <string>
#include "Course.h"
#include "Student.h"
#include "SchoolManagerSystem.h"
using namespace std;
using namespace PA4;

namespace PA4
{
Course::Course(){	s_refe = new Student[(s_size)++];	}
void Course::take_course(){        
        SchoolManagerSystem system;
        cin.ignore();
        string select_1_name, select_1_id;
        cout<<"Enter a course code and name: ";
        getline(cin, select_1_name);
        select_1_id = system.parseString(select_1_name);
      //  cout <<select_1_name<<"--"<<select_1_id<<endl;
        code=select_1_name;
        name=select_1_id;
}
}
