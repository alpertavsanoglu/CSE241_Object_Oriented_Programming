#include <iostream>
#include <string>
#include <cctype>
#include "password.h"

using namespace std;

namespace                                                       //unnamed namespace to use these only in this function
{
    string password;
    bool isValid()
    {
        if (password.length() >= 8)                             //Password length check
        {
            for (int i = 0; i < password.length(); i++)         //Non letter character check
                if (!isalpha(password[i]))  
                    return true;
        }
        return false;
    }
}

namespace Authenticate
{
    void inputPassword()
    {
        do
        {
            cout << "Enter your password(at least 8 characters and at least one non letter)" << endl;
            cin >> password;
        } while (!isValid());                       //Loop till a password matches with requirements
    }

    string getPassword()
    {
        return password;
    }
}
