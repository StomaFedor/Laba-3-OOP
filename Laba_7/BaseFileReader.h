#ifndef BASEFILEREADER_H
#define BASEFILEREADER_H

#include <string>
#include "NormalizationParameters.h"
#include "Scene.h"

using namespace std;

class BaseFileReader
{
public:
    virtual Scene ReadScene(string filename, NormalizationParameters& par) = 0;

private:

};

#endif // BASEFILEREADER_H
