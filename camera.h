#ifndef CAMERA_H#define CAMERA_H#include <glm/glm.hpp>using namespace glm;const float pi = 3.14159265359;extern float angle_deg; // in degreesextern float angle_rad; // in radiansextern float radius;extern vec3 pos;extern vec3 view;extern vec3 next_pnt;vec3 operator*(vec3 v, int d);    void MoveForward();    void MoveBack();    void PrintPosition();#endif