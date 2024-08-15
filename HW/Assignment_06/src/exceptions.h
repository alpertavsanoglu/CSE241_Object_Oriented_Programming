#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <exception>
using namespace std;

class DuplicateException : public exception{  
public:

    virtual const char* what() const throw()
    {  
        return "Exception: duplicate entry";
    }
};
class MissingException : public exception{
public:
    virtual const char* what() const throw()
    {
        return "Exception: missing field";
    }
};
class CommandException : public exception{
public:
    virtual const char* what() const throw()
    {
        return "Exception: command is wrong";
    }
};

#endif
