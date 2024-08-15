#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Student{
public:
Student():numClasses(0),classList(NULL),name(""){
}
~Student(){
    	 if(classList != NULL){
        		delete [] classList;
        		classList = NULL;
    	}	
}
void InputData(){
    	int count;
    	ResetClasses();
    	cout<<"Enter student name."<<endl;
    	getline(cin,name);
    	cout<<"Enter number of classes."<<endl;
    	cin>>numClasses;
    	cin.ignore(2,'\n');
    	if(numClasses>0){
    		classList = new string[numClasses];
			count=0;
			while(count<numClasses){
				cout<<"Enter name of class"<<(count+1)<<endl;
				getline(cin,classList[count]);
				count++;
			}
    	}
    	cout<<endl;
}
void OutputData(){
    	int count;
    	cout<<"Name: "<<name<<endl;
    	cout<<"Number of classes: "<<numClasses<<endl;
		count=0;
		while(count<numClasses){
			cout<<"  Class "<<(count+1)<<":"<<classList[count]<<endl;
			count++;
		}
		cout<<endl;
}
void ResetClasses(){
		if(classList != NULL){
         	delete [] classList;
         	classList = NULL;
		}
    	numClasses = 0;             
}
Student& operator=(const Student& rightSide){
        int count;
    	if(this->classList==rightSide.classList){
        	return *this;
    	}
    	ResetClasses();
    	name=rightSide.name;            
    	numClasses=rightSide.numClasses;
    	if(numClasses>0){
        	classList=new string[numClasses];
        	count=0;
        	while(count<numClasses){
        		classList[count] = rightSide.classList[count];
        		count++;
			}
    	}
    	return *this;
}
private:
    string name;
    int numClasses;
    string *classList;
};
int main(){
    Student s1,s2;
    s1.InputData();
    cout<<"Student 1's data:"<<endl;
    s1.OutputData();

    cout<<endl;

    s2.InputData();
    cout<<"Student 2's data:"<<endl;
    s2.OutputData();

    s2=s1;
    cout<<"Student 2's data after assignment from student 1:"<<endl;
    s2.OutputData();

    s1.ResetClasses();
    cout<<"Student 1's data after reset:"<<endl;
    s1.OutputData();
    
    cout<<"Student 2's data,should still have original classes:"<<endl;
    s2.OutputData();

    cout<<endl;
    return 0;
}
