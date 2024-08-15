#include <iostream>
#include <cstdlib>
#include <cstring>
#include <time.h>

const int MAX_TURN = 100;
using namespace std;
/*for check2 results not overlapsing with check1(temp array stores the check1's(First count) positions.*/
bool inTemp(int temp[],int i,int j,int check1);
/*For int to array*/
void intToArray(int& entry,int arr[],int digit);
/*Repetition check for secret number generator*/
bool checkRepetition(int num[],int curr,int i);
/*Playing the game*/
void play(int num[],int digit);
/*Generating random secret number*/
void secretNum(int num[],int digit);
/*Checking the number of digits on an integer*/
int digitCount(const int num);
/*Checking for First and Second counts*/
void check(int num[],int arr[],int& check1,int&check2,int digit);
/*For error checking for user inputs*/
bool check_number(char ch);
bool check_number_rule(char * ch);
/*For error checking for -r and -u*/
bool check_number_for_arguments(char ch);
bool check_number_rule_for_arguments(char * ch);

int main(int argc,char** argv ){
	int temp;
	int digit;
	int num[10];
	bool unique = true;
	
	if(argc!=3){		//If command-line argument is more than 3,exit
	cout<<"E0"<<endl;
	exit(1);
	}
	if(!strcmp(argv[1], "-r") && argv[2][1] == '\0' && check_number_rule_for_arguments(argv[2])){	//User inputs the number of digits

	digit=atoi(argv[2]);			//Turning the number of digits into integer
	if(digit<=0){				//If its negative or equal to 0,exit
	cout<<"E0"<<endl;
	exit(1);
	}
	secretNum(num,digit);			//Random secret number generator
	}
	else if(!strcmp(argv[1], "-u") && check_number_rule_for_arguments(argv[2])){	//User inputs the secret number
	
	temp=atoi(argv[2]);				//Taking the secret number as integer
	digit=digitCount(temp);				//Calculating the number of digits
	
	intToArray(temp,num,digit); 			//Assigning the 'temp' into an integer array
//	
        for (int i = 0; i < digit - 1; i++) {
            for (int j = i + 1; j < digit; j++) {
                if (num[i] == num[j]) {
                    unique = false;
                    break;
                }
            }
            if (!unique) {
                break;
            }
        }
        if (!unique) {
            cout << "E0" << endl;
            exit(1);
        }
//
	}
	else{			//If user enters any other command-line,exit
	cout<<"E0"<<endl;
	exit(1);
	}
	/*for(int i=0;i<digit;i++){
	cout<<num[i];
	}*/
	play(num,digit);	//play the game
}
/*For int to array*/
void intToArray(int& entry,int arr[],int digit){	
for(int i=digit-1;i>=0;i--){
arr[i]=entry%10;
entry/=10;
}
}
/*for check2 results not overlapsing with check1(temp array stores the check1's(First count) positions.*/
bool inTemp(int temp[],int i,int j,int check1){
for (int k=0;k<check1;k++){				//Using the other positions to check Second count)
	if(temp[k]==i)
	return false;
}
return true;
}
/*Checking for First and Second counts*/
void check(int num[],int arr[],int& check1,int& check2,int digit){
	int temp[10];							//A temporary array to store the positions for first count so it doesn't overlap with second count
	for(int i=0;i<digit;i++){		//First Count
	if(arr[i]==num[i]){
	temp[check1]=i;
	check1++;
			}
				}
	for(int i=0;i<digit;i++){		//Second count
	    for(int j=0;j<digit;j++){
	    if((arr[i]==num[j] && inTemp(temp,i,j,check1))){
	  	check2++;
	    }
	}
}
}
/*Playing the game*/
void play(int num[],int digit){

	int entry,entryDigit,arr[10],check1,check2,tryCount=0;		//Entry=user entered number,arr[10]=integer array version of entry
	bool error=false;
	char userSecretNum[10];
	do{							//Loop until user wins the game
	check1=0;						//Starting check1 and check2 from 0 on every iteration
	check2=0;
	//cout<<"Enter a number"<<endl;				//Taking the value from user
        cin >> userSecretNum;
        if(userSecretNum[0] == '0') { cout<<"E0"<<endl;		exit(1);		}	
        entry=atoi(userSecretNum);
	entryDigit=digitCount(entry);					//Digits of the entry
	
        if(!check_number_rule(userSecretNum)) 		// if entered number is not unique number or it is wrong number, print error and exit
        {
            cout << "E2" << endl;
            exit(1);
        }
        if(entryDigit!=digit){						//If the number of digits on user entry doesnt match with the secret numbers,exit
	cout<<"E1"<<endl;
	exit(1);
	}
	intToArray(entry,arr,digit);					//Assigning the 'entry' into an integer array
	
	for(int i=0;i<digit;i++){					//Checking for repeated numbers in user entered value
		for(int j=i+1;j<digit;j++){
		if(arr[i]==arr[j])	error=true;
		}
	}
	if(error==true){						//Exiting if there is a repeat
	cout<<"E0"<<endl;
	exit(1);
	}

	check(num,arr,check1,check2,digit);					//Calling for check counts
	if(check1!=digit)cout<<check1<<" "<<check2<<endl;			/* cout<<"First count is "<<check1<<", Second count is "<<check2; */ 
	tryCount++;								//Counting the loops 
	//cout<<endl;
	if(check1==digit){ cout<<"FOUND "<<tryCount<<endl; exit(1);	}					//If program isn't exited,user won the game
	}while(tryCount!=MAX_TURN );							//End the loop if user matches all numbers
	cout<<"FAILED"<<endl;
	exit(1);
}
/*Repetition check for secret number generator*/
bool checkRepetition(int num[],int curr,int i){					
	for (int j=0;j<i;j++){
			if(curr==num[j]){
					return true;
					}
			}
		return false;
}
/*Generating random secret number*/
void secretNum(int num[],int digit){

	int curr,x=0;							//current number
	bool rep;							//Repetition check
	srand(time(NULL));						//Random number generator
	for(int i=0;i<digit;i++){
		do{
	
		curr=rand()%10;
		rep=checkRepetition(num,curr,i);
			}while(rep || (i==0 && curr==0));		//Loop while first entry isn't 0 or the number isn't repeating 
	num[i]=curr;							//Assign the new number to integer array
	}
}
/*Checking the number of digits on an integer*/
int digitCount(const int num){
	int digitCount=1,temp=num;
if(temp >= 0 && temp < 10){
		digitCount=0;			// for 1 digit number
do{
		temp=temp/10;
		digitCount++;
}while(temp>9);
		return digitCount;
}
else{						//more than 1 digit number
do{
		temp=temp/10;
		digitCount++;
}while(temp>9);
		return digitCount;
}
}
/*For error checking for user inputs*/
bool check_number(char ch){
    if(47 < ch && ch < 58) return true;		 				// if user enter other than integer
    cout << "E2" << endl;
    exit(1);
}
bool check_number_rule(char * ch){
    if(ch[0] == '0') return false;						// check 0 for first number 
    else{
        for(int i = 0; ch[i] != '\0'; ++i){					// check whole array
            if(!check_number(ch[i])) return false;   
        }
        return true;   
    }
}
/*For error checking for -r and -u*/
bool check_number_rule_for_arguments(char * ch){
    if(ch[0] == '0') return false;						// check 0 for first number 
    else{
        for(int i = 0; ch[i] != '\0'; ++i){					// check whole array
            if(!check_number_for_arguments(ch[i])) return false;   			
        }
        return true;   
    }
}
bool check_number_for_arguments(char ch){
    if(47 < ch && ch < 58) return true;		 				// if user enter other than integer
    cout << "E0" << endl;
    exit(1);
}
