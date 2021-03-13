#ifndef CAMERA_H
#define CAMERA_H
#include "point.h"

class Camera
{
public:
    float pi = 3.14159265359;
    float angle_deg = 1; // in degrees
    float angle_rad = 1.57; // in radians
    float radius = 0.02;
    Point pos = Point("position", 0, 0.3, 0);
    Point view = Point("view", 0, 0.3, 0.02);
    Point next_pnt;

    Camera();
    void MoveForward();
    void MoveBack();
    void TurnLeft();
    void TurnRight();
    void PrintPosition();
    float ToRadians(float degree);
};

#endif // CAMERA_H
