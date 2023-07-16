#pragma once
#include <exception>

class MyException : public std::exception
{
public:
    MyException (const char* message, int codeError);   
    ~MyException(){delete[] message_;}    
    
    const char* what () const throw() override;

private:
    char* message_;    
};