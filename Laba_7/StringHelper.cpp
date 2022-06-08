#include "StringHelper.h"

vector<string> StringHelper::strSplit(string str)
{
    vector<string> newLine;
    string buffer = "";
    for(size_t i = 0; i < str.size(); i++){
        if(str[i] != ',')
              buffer += str[i];
        else {
              newLine.push_back(buffer);
              buffer = "";
        }
    }
    newLine.push_back(buffer);
    return newLine;
}
