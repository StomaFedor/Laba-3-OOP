#ifndef FILEREADER_H
#define FILEREADER_H

#include "BaseFileReader.h"
#include "NormalizationParameters.h"
#include "Scene.h"
#include "FacadeException.h"
#include "StringHelper.h"

#define BUFF_SIZE 300

using namespace std;

class FileReader: public BaseFileReader
{
public:
    Scene ReadScene(string filename, NormalizationParameters& par) override;

private:

    Figure AddFigure(vector<vector <float>> &ValuesX, vector<vector <float>> &ValuesY, vector<vector <float>> &ValuesZ);

    vector<string> GetNakedData(string filename);

    vector<vector<string>> GetSplitData(string filename);

    vector<vector<float>> ConvertStringToNumber(vector<vector<string>>& stringZ);

    void CreateXYValues(vector<vector<float> >& valuesZ, vector<vector<float>>& valuesX, vector<vector<float>>& valuesY,  NormalizationParameters& par);
};

#endif // FILEREADER_H
