#include <iostream>
#include <string>
#include <sstream>
#include "Student.h"
#include "Course.h"
#include "SchoolManagerSystem.h"
using namespace std;
using namespace PA4;

namespace PA4
{
int SchoolManagerSystem::menu(){						// menu for system
	cout << "Main_Menu" << endl;
	int select;
	do{
            cout<< "0 exit" << endl
            	<< "1 student" << endl
            	<< "2 course" << endl
            	<< "3 list_all_students" << endl
            	<< "4 list_all_courses" << endl;
            cin >> select;
            if(select == 0)
            {
                break;
            }
            else if(select == 1)
            {
                int sub_c;
                do
                {
                    
                    cout<< "0 up" << endl
                    	<< "1 add_student" << endl
                    	<< "2 select_student" << endl;
                    cin >> sub_c;
                    if(sub_c == 0)
                    {
                        break;
                    }
                    else if(sub_c == 1)
                    {
                        add_student();
                    }
                    else if(sub_c == 2)
                    {
                        Student obj_s = select_student();
                        int select_s;
                        do
                        {
                            cout<< "0 up" << endl
                            	<< "1 delete_student" << endl
                            	<< "2 add_selected_student_to_a_course" << endl
                            	<< "3 drop_selected_student_from_a_course" << endl;
                            cin >> select_s;
                            if(select_s == 0)
                            {
                                break;
                            }
                            else if(select_s == 1)
                            {
                                string str_del = obj_s.name;
                                int int_del = obj_s.id;
                                delete_student(str_del,int_del);
                            }
                            else if(select_s == 2)
                            {
                                add_selected_student_to_a_course(obj_s);
                            }
                            else if(select_s == 3)
                            {
                                drop_selected_student_from_a_course(obj_s);
                            }
                        }while(select_s < 0 || select_s > 3);
                    }

                }while(sub_c < 0 || sub_c > 2);
            }
            else if(select == 2)
            {
                int select_course_menu;
                do
                {
                    cout<< "0 up" << endl
                    	<< "1 add_course" << endl
                    	<< "2 select_course" << endl;
                    cin >> select_course_menu;
                    if(select_course_menu == 0)
                    {
                        break;
                    }
                    else if(select_course_menu == 1)
                    {
                        add_course();
                    }
                    else if(select_course_menu == 2)
                    {
                        Course obj = select_course();
                        int select_course_s;
                        do
                        {
                            cout<< "0 up" << endl
                            	<< "1 delete_course" << endl
                            	<< "2 list_students_registered_to_the_selected_course" << endl;
                            cin >> select_course_s;
                            if(select_course_s == 0)
                            {
                                break;
                            }
                            else if(select_course_s == 1)
                            {
                                string str1 = obj.name;
                                string str2 = obj.code;
                                delete_course(str1,str2);
                            }
                            else if(select_course_s == 2)
                            {
                                list_students_registered_to_the_selected_course(obj);
                            }
                        } while (select_course_s < 0 || select_course_s > 2);
                        
                    }

                }while(select < 0 || select >2);
                
            }
            else if(select == 3)
            {
                int i_for_c3=0;
    		while(i_for_c3 < s_size){
    			cout << s_ref[i_for_c3].name << " " << s_ref[i_for_c3].id << endl;
    			i_for_c3++;
    		}
            }
            else if(select == 4)
            {
                int i_for_c4=0;
    		while(i_for_c4 <c_size){
    			cout << c_ref[i_for_c4].code << " " << c_ref[i_for_c4].name << endl;
    		i_for_c4++;
    		}
            }

        } while (select > 4 || select < 0);
        return select;
}
void SchoolManagerSystem::add_student(){				//adding student
	int counter=0;
	s_size++;
        Student *obj = new Student[s_size];

        while(counter<s_size-1){
            obj[counter] = s_ref[counter];
            counter++;
        }

        delete[] s_ref;
        s_ref = obj;
        obj[s_size-1].take_student(); 
}
void SchoolManagerSystem::add_course(){				//adding course
        Course *obj = new Course[c_size + 1];
        int i=0;
        while(i < c_size){
        obj[i] = c_ref[i];
        i++;
        }
        delete[] c_ref;
        c_ref = obj;
        obj[c_size++].take_course();
}
Course SchoolManagerSystem::select_course(){			//select course from entered
        Course temp;
        cin.ignore();
        string select_1_name, select_1_id;
        cout<<"Enter a course code and name: ";
        getline(cin, select_1_name);
        select_1_id = parseString(select_1_name);
       // cout <<select_1_name<<"--"<<select_1_id<<endl;
	temp.code=select_1_name;
        temp.name=select_1_id;
        return temp;
}
Student SchoolManagerSystem::select_student(){			//select student from entered
        Student temp;
        cin.ignore();
        string select_1_name, select_1_id;
        cout<<"Enter a student name and ID: ";
        getline(cin, select_1_name);
        select_1_id = parseString(select_1_name);
     //   cout <<select_1_name<<"--"<<select_1_id<<endl;
        int id_int= stoi(select_1_id);
        temp.name=select_1_name;
        temp.id=id_int;
        return temp;    
}
void SchoolManagerSystem::delete_student(string str, int int_del){			//deleting student from entered
        Student *temp = NULL;
        s_size--;
        int cond = -1;
        int i = 0,j=0;
        while((i < s_size+1) && (cond == -1)){
        	if((s_ref[i].name == str) && (s_ref[i].id == int_del)){
                cond = i;
            	}
        i++;
        }
        if(s_size+1 > 1){
            temp = new Student[s_size];
        }
        i = 0,j = 0;
        while(i < s_size+1){
        	if(i != cond){
                temp[j] = s_ref[i];
                j++;
            }
        i++;
        }
        delete[] s_ref;
        s_ref = temp;
}
void SchoolManagerSystem::delete_course(string str1,string str2){			//deleting course from entered
        Course *obj = NULL;
        c_size--;
        int cond = -1;
        int i=0,j=0;
        while((i < c_size+1) && (cond == -1)){
        	if((c_ref[i].name == str1) && (c_ref[i].code == str2)){
               	cond = i;
          	}
        i++;
        }
	if(c_size+1 > 1){
            obj = new Course[c_size ];
        }
	i=0,j=0;
	while(i < c_size+1){
		if(i != cond){
                	obj[j] = c_ref[i];
                	j++;
            	}
	i++;
	}    
        delete[] c_ref;
        c_ref = obj;
}
void SchoolManagerSystem::add_selected_student_to_a_course(Student obj){			//add student to the course which is created
int cond= 0,k,i=0,pick_course;
	while(i < s_size){
		if((s_ref[i].name == obj.name) && (s_ref[i].id == obj.id)){
                cond = 1;
                k = i; 
		}
	i++;
	}
	i=0;
	while(i < c_size){
	if(cond == 1)
            {
                if((c_ref[i].name != s_ref[k].c_refe[i].name) && (c_ref[i].code != s_ref[k].c_refe[i].code))
                {
                    cout << i+1 << " " << c_ref[i].code << " " << c_ref[i].name << endl;
                } 
            }
        i++;
        }
        cout << "Choose a course: ";
        cin >> pick_course;
        pick_course=pick_course-1;
        s_ref[k].c_refe[pick_course].name = c_ref[pick_course].name;
        s_ref[k].c_refe[pick_course].code = c_ref[pick_course].code;
}
void SchoolManagerSystem::drop_selected_student_from_a_course(Student obj){			//leaving course which is created
        int cond = 0,k,i=0,pick_course;

        while(i < s_size){
        	if((s_ref[i].name == obj.name) && (s_ref[i].id == obj.id)){
                cond = 1;
                k = i;
            }
        i++;
        }
        i=0;
        while( i < c_size){
        if(cond == 1)
            {
                if((c_ref[i].name == s_ref[k].c_refe[i].name) && (c_ref[i].code == s_ref[k].c_refe[i].code))
                {
                    cout << i+1 << " " << c_ref[i].code << " " << c_ref[i].name << endl;
                } 
            }
        i++;
        }
        cout << "Choose a course: ";
        cin >> pick_course;
        pick_course=pick_course-1;
        s_ref[k].c_refe[pick_course].name = "";
        s_ref[k].c_refe[pick_course].code = "";
}
void SchoolManagerSystem::list_students_registered_to_the_selected_course(Course obj){   		//list registired courses
        int cond = 0,k,i=0,j=0;
        
        while(i < c_size){
        if((c_ref[i].name == obj.name) && (c_ref[i].code == obj.code)){
                cond = 1;
                k = i;   
            }
        
        i++;
        }
	i=0;
	while(i < s_size){
		j=0;
		while(j < c_size){
			if(cond == 1){
                    		if((c_ref[k].name == s_ref[i].c_refe[j].name) && (c_ref[k].code == s_ref[i].c_refe[j].code)){
                        		cout << s_ref[i].name << " " << s_ref[i].id << endl;
                    		} 
                	}
		j++;
		}
	i++;
	}
}
string SchoolManagerSystem::parseStr(string &x){            //Parsing the string for code and name(If entry is CSE241 oop,CSE241 is code,rest is name)
        istringstream line(x);
        string code, name, temp,tem;
        line >> code;
        int i=0;
        while (line >> temp)
        {
        if(i>=2){
           name += " ";
        }
        else{
            name += "";
            name += temp;
            }
            i++;
        }
        x=name;
        return code;
}
string SchoolManagerSystem::parseString(string &x){              //Parsing name and id from a string(if entry is alper 386,386 is id,alper is name)
        istringstream line(x);
        string id, name, temp,tem;
        int i=0;
        while (line >> temp)
        {
        if( i>=2){
           name += " ";
           i++;
        }
        else{
            name += "";
        }
            name += temp;
            i++;
        }
        int a1=temp.length();
        int a2=name.length();
        tem=name.substr(0,a2-a1);
        x = tem;
        return temp;
}
SchoolManagerSystem::SchoolManagerSystem(){
        s_ref = new Student[s_size];
        c_ref = new Course[c_size];
}
SchoolManagerSystem::~SchoolManagerSystem(){
            delete[] s_ref;
            delete[] c_ref;
}
}
