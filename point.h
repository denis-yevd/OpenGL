#ifndef POINT_H
#define POINT_H


class Point
{
public:
    float x;
    float y;
    Point(float x, float y);
    Point operator +(Point point);
    Point operator -(Point point);
    void operator =(Point point);
    void operator *(float number);

};

#endif // POINT_H
