#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

class DynamicStringArray // declaring class constructors
{
public:
DynamicStringArray(){	// default constructor
    dynamicArray = NULL;
    size = 0;
}
~DynamicStringArray(){
    if(dynamicArray != NULL)
    {
        delete[] dynamicArray;
    }
}
int getSize(){
    return size;
}
string getEntry(int count){
    if((count < 0) || (count >= size)){
        return NULL;
    }
    return dynamicArray[count];
}    
DynamicStringArray(const DynamicStringArray &newObj){
    int i;
    size = newObj.size;
    if (size == 0)
    {
        dynamicArray = NULL;
    }
    else
    {
        dynamicArray = new string[size];
        i=0;
        while(i<size){
        dynamicArray[i] = newObj.dynamicArray[i];
        i++;
        }
    }
}
void addEntry(string str){
    //adding entry to a temp array,after deleting the normal array,assigning temp to normal
    int i;
    string *newArray = new string[size + 1];
    i=0;
    while(i<size){
    newArray[i] = dynamicArray[i];
    i++;
    }
    delete[] this->dynamicArray;
    this->dynamicArray = newArray; 
    newArray[size++] = str;
}
bool deleteEntry(string str){	//Deleting an entry from the array
    string *result = NULL;
    int pos = -1;

    for(int i = 0; (i < size) && (pos == -1); i++) 
    {
        if(dynamicArray[i] == str)
        {
            pos = i;
        }
    }
    if(pos == -1)                  //if no entry
    {
        return false;
    }
    if(size > 1)
    {
        result = new string[size - 1];
    }
    for(int i = 0, j = 0; i < size; i++)
    {
        if(i != pos)
        {
            result[j++] = dynamicArray[i];
        }
    }
    size--;
    delete[] dynamicArray;              //Emptying it and assigning the new value
    dynamicArray = result;

    return true;
}
DynamicStringArray &operator=(const DynamicStringArray &obj){
    int i;
    if(this->dynamicArray == obj.dynamicArray){               //no operation needed if they are already equal
        return *this;
    }
    if(this->dynamicArray != NULL){                                   //emptying the left hand side array
        delete[] dynamicArray;
    }
    if(obj.size == 0)                                            //if right hand side is empty,assigning empty values
    {
        size = 0;
        dynamicArray = NULL;
    }
    else
    {
        size = obj.size;
        dynamicArray = new string[size];
        i=0;
        while(i<size){
        dynamicArray[i] = obj.dynamicArray[i];
        i++;
        }
    }
    return *this;
}
private:
    string *dynamicArray;
    int size;
};

int main(){
    DynamicStringArray names;

    names.addEntry("abcd");
    names.addEntry("efgh");
    names.addEntry("anivia");
    names.addEntry("black");

    cout << "List of names: " << endl;
    for(int i = 0; i<names.getSize(); i++)
    cout << names.getEntry(i) << endl;
    cout << endl;

    names.addEntry("lufi");
    cout << "After adding a name: " << endl;
    for(int i = 0; i<names.getSize(); i++)
    cout << names.getEntry(i) << endl;
    cout << endl;

    names.deleteEntry("efgh");
    cout << "After removing a name: " << endl;
    for(int i = 0; i<names.getSize(); i++)
    cout << names.getEntry(i) << endl;
    cout << endl;

    names.deleteEntry("frost");
    cout << "After removing a name that isn't on the list: " << endl;
    for(int i = 0; i<names.getSize(); i++)
    cout << names.getEntry(i) << endl;
    cout << endl;

    names.addEntry("Shadow");
    cout << "After adding another name: " << endl;
    for(int i = 0; i<names.getSize(); i++)
    cout << names.getEntry(i) << endl;
    cout << endl;

    while (names.getSize() > 0){
        names.deleteEntry(names.getEntry(names.getSize() - 1));
    }

    cout << "After removing all of the names: " << endl;
    for(int i = 0; i<names.getSize(); i++)
    cout << names.getEntry(i) << endl;
    cout << endl;

    names.addEntry("alper");
    cout << "After adding a name: " << endl;
    for(int i = 0; i<names.getSize(); i++)
    cout << names.getEntry(i) << endl;
    cout << endl;

    cout << "Testing copy constructor" << endl;
    DynamicStringArray names2(names);

    names.deleteEntry("alper");
    cout << "Copied names: " << endl;
    for(int i = 0; i<names2.getSize(); i++)
    cout << names2.getEntry(i) << endl;
    cout << endl;

    cout << "Testing assignment" << endl;
    DynamicStringArray names3 = names2;
    names2.deleteEntry("alper");
    cout << "Copied names: " << endl;
    for(int i = 0; i<names3.getSize(); i++)
    cout << names3.getEntry(i) << endl;
    cout << endl;

    cout << "Enter a character to exit." << endl;
    char wait;
    cin >> wait;
    return 0;
}
