#include "camera.h"
#include <math.h>

Camera::Camera()
{
    //angle_rad = ToRadians(angle_deg);
}

float Camera::ToRadians(float degree){
    return (degree * pi/180);
}

void Camera::MoveForward(){
    Point d = view - pos;
    d * 2;
    next_pnt = pos + d;
    pos = view;
    view = next_pnt;
}

void Camera::MoveBack(){
    Point d = view - pos;
    next_pnt = pos - d;
    view = pos;
    pos = next_pnt;
}

void Camera::TurnLeft(){
    angle_rad -=0.02;
    view.x = pos.x + (radius * cos(angle_rad));
    view.z = pos.z + (radius * sin(angle_rad));
}

void Camera::TurnRight(){
    angle_rad +=0.02;
    view.x = pos.x + (radius * cos(angle_rad));
    view.z = pos.z + (radius * sin(angle_rad));
}

void Camera::PrintPosition(){
    this->pos.PrintCoords();
    this->view.PrintCoords();
}
