#include <iostream>
#include <cstdlib>
#include <cctype>

using namespace std;

const int NUM_OF_MAX_DIGIT = 20;    /*maximum length of the integers*/

void num_from_user(int num[], int& length_of_number)    /*func for taking numbers from*/
{
    int i; 
    int str;
    length_of_number = 0;
    i=0;
    char digit;
    cin.get(digit);
    while('\n' != digit)                                /*until end of the number*/
    {   
        if(!isdigit(digit))                             /*if user didnt enter a digit*/
        {
            cout <<"input number invalid." <<"\n";
            exit(1);
        }
        num[i] = int(digit) - '0';
        length_of_number++;
        i++;
        cin.get(digit);
    }
    if(length_of_number > NUM_OF_MAX_DIGIT)                 /*if user entered more than 20 digit*/
    {
        cout << "Input number size is larger than " << NUM_OF_MAX_DIGIT << "\n";
        exit(1);
    }
    i=0;
    while(i<length_of_number/2){                                        /*for reversing array*/
                                str = num[i];
                                num[i] = num[length_of_number -1 -i];
                                num[length_of_number - 1 - i] = str;
                                i++;
                                }
}

int main()
{ 
    int num_one[NUM_OF_MAX_DIGIT+1];
    int num_two[NUM_OF_MAX_DIGIT+1];
    int total[NUM_OF_MAX_DIGIT+1];
    int user;
    string str;
    int a;
    int length_one;
    int length_two;
    int length_total;
    int carry;
    int bigger_size;
    
    do{
            cout << "1. Add two numbers\n"               /*Print menu*/
                 << "0. Exit\n";
    cin>> user;
    getline(cin, str);
    if(user == 1){
    cout << "Enter two integers with max " << NUM_OF_MAX_DIGIT << " digits:\n";
    num_from_user(num_one,length_one);                                              /*take numbers from user*/
    num_from_user(num_two,length_two);                                              /*take numbers from user*/
    cout << "Result is:\n";
    a=NUM_OF_MAX_DIGIT;                 /*for printing numbers*/
    while(a>=length_one){
                cout <<" ";
                a--;
                        }
    a=length_one-1;
     while(a>=0){
                cout <<num_one[a];
                a--;
                        }
    cout << "\n";
    
    a=NUM_OF_MAX_DIGIT;                 /*for printing numbers*/
    while(a>=length_two){
                cout <<" ";
                a--;
                        }
    a=length_two-1;
     while(a>=0){
                cout <<num_two[a];
                a--;
                        }
    cout <<"\n-----------------------\n";       /*for paper-and-pencil addition*/

    if(length_one > length_two)                 /*comparison the numbers size*/
    {
            a = length_two;
            while(a<length_one){
                num_two[a] = 0;
                a++;
            }
            bigger_size = length_one;
    }
    else                                          /*comparison the numbers size*/
    {
        a=length_one;
        while(a<length_two){
                num_one[a] = 0;
                a++;
            }
            bigger_size = length_two;
    }
        a=0;
        carry=0;
        while(a<bigger_size){
                            total[a] = num_one[a] + num_two[a] + carry;     /*add the numbers*/
                            if(total[a] > 9){
                                            carry = 1;
                                            total[a] = total[a] - 10;       /*if addition higher than 9*/
                                            } 
                            else{
                                carry = 0;              /*if addition not higher than 9*/
                                }
                            a++;
                            }
    if(carry == 1)                      /*if there is carry from addition*/
    {
        if(bigger_size == NUM_OF_MAX_DIGIT)             
        {
            cout << "Integer overflow occured.\n";      /*if addition size more than 20*/
            exit(1);
        }
        else
        {
            total[bigger_size] = carry;
            length_total = bigger_size + 1;
        }
    }
    else{                               /*if there is no carry from addition*/
        length_total = bigger_size;
    }
    
    a=NUM_OF_MAX_DIGIT;                 /*for printing output*/
    while(a>=length_total){
                        cout <<" ";
                        a--;
                        }
    a=length_total-1;
    while(a>=0){
                    cout <<total[a];
                    a--;
                        }
    cout << "\n";
}
 else if(user){
                cout << "Invalid input!\n";     /*if user enter other than menu*/
                }
    }while(user);                           /*if user enter 0*/
    return 0;
}
