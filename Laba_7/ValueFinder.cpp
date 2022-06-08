#include "ValueFinder.h"


float ValueFinder::FindMinZ(vector<Vertex> arr)
{
    float min = arr[0].GetPosition().Y;

    for(size_t i = 0; i < arr.size(); i++)
        if(arr[i].GetPosition().Y < min)
            min = arr[i].GetPosition().Y;

    return min;
}

float ValueFinder::FindMaxZ(vector<Vertex> arr)
{
    float max = arr[0].GetPosition().Y;

    for(size_t i = 0; i < arr.size(); i++)
        if(arr[i].GetPosition().Y > max)
            max = arr[i].GetPosition().Y;

    return max;
}
