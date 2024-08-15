#include <iostream>
#include <string>
#include <cctype>
#include "password.h"

using namespace std;

namespace                                                  //unnamed namespace to use these only in this function
{
    string username;
    bool isValid()
    {
        if (username.length() == 8)                     //length check
            return true;
            return false;
    }
}

namespace Authenticate
{
    void inputUserName()
    {
        do
        {
        cout<<"Enter your username"<<"(8 letters only)"<<endl;
        cin>>username;
        } while (!isValid());                            //Loop till a password matches with requirements
        
    }

    string getUserName()
    {
        return username;
    }
}
