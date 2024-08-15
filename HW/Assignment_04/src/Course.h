#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

namespace PA4
{
class Student;
	class Course{
	public:
		Course();
		void take_course();
		string name;
		string code;
		Student *s_refe;
		int s_size=0;
	};
}
#endif
