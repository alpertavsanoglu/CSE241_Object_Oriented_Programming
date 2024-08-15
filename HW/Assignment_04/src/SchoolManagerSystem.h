#ifndef SchoolManagerSystem_h
#define SchoolManagerSystem_h
#include <iostream>
#include <string>
#include "Course.h"
#include "Student.h"
using namespace std;

namespace PA4
{
class Course;
class Student;
	class SchoolManagerSystem
	{
	public:
		SchoolManagerSystem();
		~SchoolManagerSystem();
		Student select_student();
		Student *s_ref;
		Course select_course();
		Course *c_ref;
		int menu();
		int s_size=0;
		int c_size=0;
		string parseString(string &x);
		string parseStr(string &x);
		void add_student();
		void delete_student(string str, int int_del);
		void add_selected_student_to_a_course(Student obj);
		void drop_selected_student_from_a_course(Student obj);
		void add_course();
		void delete_course(string str1,string str2);
		void list_students_registered_to_the_selected_course(Course obj);
	};
}
#endif
