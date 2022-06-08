#include "FileReader.h"

#include <iostream>

Scene FileReader::ReadScene(string filename, NormalizationParameters &par)
{
    vector<vector<string>> stringZ = GetSplitData(filename);
    vector<vector<float>> valuesY = ConvertStringToNumber(stringZ);

    vector<vector<float> > valuesX;
    vector<vector<float> > valuesZ;
    CreateXYValues(valuesY, valuesX, valuesZ, par);

    Figure fig;
    fig = AddFigure(valuesX, valuesY, valuesZ);

    Scene scene;
    scene.AddFigure(fig);
    scene.NormalizeFigures(par);

    return scene;

}

Figure FileReader::AddFigure(vector<vector <float>> &X, vector<vector <float>> &Y, vector<vector <float>> &Z)
{
    Figure fig;
    Vertex vertex;
    for (size_t i = 0; i < Z.size(); i++)
        for (size_t j = 0; j < Z[i].size(); j++) {
            vertex.SetPosition(X[i][j], Y[i][j], Z[i][j]);
            fig.AddVertex(vertex);
        }
    vector<Vertex> V = fig.GetVertices();
    for (size_t i = 0; i < Z.size(); i++)
        for (size_t j = 0; j < Z[i].size(); j++) {
            if (i != Z.size() - 1) {
                Edge edge(V[i * Z.size() + j], V[i * Z.size() + j + Z.size()]);
                fig.AddEdge(edge);
            }
            if (j != Z[i].size() - 1) {
                Edge edge(V[i * Z.size() + j], V[i * Z.size() + j + 1]);
                fig.AddEdge(edge);
            }
    }
    return fig;
}

vector<string> FileReader::GetNakedData(string filename)
{
    FILE* file = fopen(filename.c_str(), "r");
    if (!file)
        throw FacadeException("Could not open the file");
    vector<string> data;
    char line[BUFF_SIZE];
    while (fgets(line, BUFF_SIZE, file))
    {
        data.push_back(line);
    }
    fclose(file);
    return data;
}

vector<vector<string> > FileReader::GetSplitData(string filename)
{
    vector<string> data = GetNakedData(filename);
    vector<vector<string>> stringZ;
    vector<string> newData;
    for (size_t i = 0; i < data.size(); i++) {
        newData = StringHelper::strSplit(data[i]);
        stringZ.push_back(newData);
    }
    return stringZ;
}

vector<vector<float>> FileReader::ConvertStringToNumber(vector<vector<string> > &stringZ)
{
    vector<vector<float>> arr;
    vector<float> line;
    for (size_t i = 0; i < stringZ.size(); i++) {
        for (size_t j = 0; j < stringZ[i].size(); j++)
            line.push_back(atof(stringZ[i][j].c_str()));
        arr.push_back(line);
        line.clear();
    }
    return arr;
}

void FileReader::CreateXYValues(vector<vector<float> > &valuesZ, vector<vector<float>>& valuesX, vector<vector<float>>& valuesY,  NormalizationParameters &par)
{
    vector<float> lineI, lineJ;
    for (size_t i = 0; i < valuesZ.size(); i++) {
        for (size_t j = 0; j < valuesZ[i].size(); j++) {
            lineI.push_back(i * par.DxStep);
            lineJ.push_back(j * par.DyStep);

        }
        valuesX.push_back(lineI);
        valuesY.push_back(lineJ);
        lineI.clear();
        lineJ.clear();
    }
}
