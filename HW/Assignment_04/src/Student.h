#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include "Course.h"
using namespace std;

namespace PA4
{
    class Course;
    class Student{
        public:
            Student();
            void take_student();
            string name;
            int id;
            Course *c_refe;
            int c_size=40;
    };
}
#endif
