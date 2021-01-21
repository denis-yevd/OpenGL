#include "point.h"

Point::Point(float x, float y)
{
    this->x = x;
    this->y = y;
}

Point Point::operator +(Point point){
    float newX = this->x + point.x;
    float newY = this->y + point.y;
    return Point(newX, newY);
}

Point Point::operator -(Point point){
    float newX = this->x - point.x;
    float newY = this->y - point.y;
    return Point(newX, newY);
}

void Point::operator =(Point point){
    this->x = point.x;
    this->y = point.y;
}

void Point::operator *(float number){
    this->x *= number;
    this->y *= number;
}
