#ifndef FACADEEXCEPTION_H
#define FACADEEXCEPTION_H

#include <stdexcept>
#include <string>

using namespace std;

class FacadeException: public invalid_argument
{
public:
    FacadeException(string msg): invalid_argument(msg)
    {
    }
};

#endif // FACADEEXCEPTION_H
