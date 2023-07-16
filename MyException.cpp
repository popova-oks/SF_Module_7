#pragma warning(disable : 4996)
#include "MyException.h"
#include <iostream>

MyException::MyException (const char* message, int codeError)
{
    char formattedMessage[100];
    snprintf(formattedMessage, sizeof(formattedMessage), 
                "MyException: %s CODE ERROR: %d", message, codeError);
    message_ = new char[strlen(formattedMessage) + 1]{};
    strcat (message_, formattedMessage);
}

const char* MyException::what () const throw ()
{
    return message_;
}
