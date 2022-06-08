#ifndef VALUEFINDER_H
#define VALUEFINDER_H

#include <vector>

#include "Point3D.h"
#include "Vertex.h"

using namespace std;

class ValueFinder
{
public:
    static float FindMinZ(vector<Vertex> arr);

    static float FindMaxZ(vector<Vertex> arr);
};

#endif // VALUEFINDER_H
