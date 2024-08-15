#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

class MyInteger
{
public:

MyInteger(){
	num=0;
}
int getValue(){
	return num;
}
MyInteger(int value){
	num=value;
}
void setValue(int value){
	num=value;
}
int operator[](int i) const{					//Overloading [] operator	
	if (i < 0 || i >= getNumDigits()){				//Error check
	return -1;
	}
	int digit = (num / static_cast<int>(pow(10, i))) % 10;		//Rightmost digit is the answer
	return digit;
}
private:
int num;
int getNumDigits() const{				//if it exceeds the number of digits
        if(num == 0){
            return 1;
        }
int numDigits = 0;
int temp = abs(num);
while (temp > 0){
	temp /= 10;
	numDigits++;
        }
	return numDigits;
}
};

int main()
{	
	//Code Tester
	MyInteger num(1234);
	
	cout<<num[0]<<" "<<num[1]<<" "<<num[2]<<endl;
	cout<<num[3]<<endl;			
	cout<<num[-1]<<endl;
}
