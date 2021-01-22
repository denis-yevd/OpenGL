#include <string>
#include <cstring>
#ifndef POINT_H
#define POINT_H

using namespace std;

class Point
{
public:
    string name;
    float x;
    float y;
    float z;
    Point();
    Point(float x, float y, float z);
    Point(string name, float x, float y, float z);
    Point operator +(Point point);
    Point operator -(Point point);
    void operator =(Point point);
    void operator *(float number);
    void PrintCoords();
};

#endif // POINT_H
