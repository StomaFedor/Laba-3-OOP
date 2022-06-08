#ifndef FACADEOPERATIONRESULT_H
#define FACADEOPERATIONRESULT_H

#include <string>

using namespace std;


class FacadeOperationResult
{
private:
    string _errorMessage;

    bool _isSuccess;

public:
    string GetErrorMessage();

    bool IsSuccess();

};

#endif // FACADEOPERATIONRESULT_H
