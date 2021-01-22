#include "point.h"
#include<iostream>

Point::Point(){
    this->name = "anonymous";
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Point::Point(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Point::Point(string name, float x, float y, float z){
    this->name=name;
    this->x = x;
    this->y = y;
    this->z = z;
}

Point Point::operator +(Point point){
    float newX = this->x + point.x;
    float newY = this->y + point.y;
    float newZ = this->z + point.z;
    return Point(newX, newY, newZ);
}

Point Point::operator -(Point point){
    float newX = this->x - point.x;
    float newY = this->y - point.y;
    float newZ = this->z - point.z;
    return Point(newX, newY, newZ);
}

void Point::operator =(Point point){
    this->x = point.x;
    this->y = point.y;
    this->z = point.z;
}

void Point::operator *(float number){
    this->x *= number;
    this->y *= number;
    this->z *= number;
}

void Point::PrintCoords(){
    cout<<name<<'\n';
    cout<<"x: "<<this->x<<' ';
    cout<<"y: "<<this->y<<' ';
    cout<<"z: "<<this->z<<'\n';
}
