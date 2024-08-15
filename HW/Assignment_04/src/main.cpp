#include <iostream>
#include <string>
#include "Student.h"
#include "Course.h"
#include "SchoolManagerSystem.h"

using namespace std;
using namespace PA4;

int main()
{
    SchoolManagerSystem system;
    int flag = 1;
    while(flag != 0)
    {
        flag = system.menu();
    }
    return 0;
}
