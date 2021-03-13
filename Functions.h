#define STB_IMAGE_IMPLEMENTATION
#include <GL/glut.h>
#include <stb_image.h>
#include <iostream>
#include <stdio.h>
#include <dirent.h>
#include <glm/glm.hpp>
#include "point.h"
#include "camera.h"

int wnd_width=1300;
int wnd_height=900;
GLdouble aspect = wnd_width/wnd_height;
Camera cam;
unsigned int texture_floor;
unsigned int texture_wall;
float text_coords[] = {0,0, 1,0, 1,1, 0,1};
int prev_mouse_x=0;
int prev_mouse_y=0;
int tmp=0;

void DrawFloor(float x, float y, float z, float width,
               float length, float lift=0); // x, y, z - center start point);
void DrawWall(float x1, float z1, float x2, float z2);
void KeyPressed(int key, int x, int y);
void TextureInit(char* file);
void display();
void Idle();

void TextureInit(char* file){
    int width, height, cnt;
    unsigned char* data = stbi_load(file, &width, &height, &cnt, 0);
    if(data==nullptr) std::cout<< "NO\n";
    else std::cout<<width<<'\t'<<height<<'\n';
    glGenTextures(1, &texture_floor);
    glBindTexture(GL_TEXTURE_2D, texture_floor);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height,
                 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data);
}

void display(){
    glClearColor(0.6, 0.8, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90, aspect, 0.1, 5);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(cam.pos.x, cam.pos.y, cam.pos.z,
              cam.view.x, cam.view.y, cam.view.z,
              0, 0.2, 0);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture_floor);

    glBegin(GL_QUADS);

    DrawFloor(0, 0, 0, 1.5, 2.5);
    DrawFloor(0, 0, 2.5, 1.5, 5);

    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    DrawWall(-0.5, 0.1, -0.5, 2);
    DrawWall(0.5, 0.1, 0.5, 1.7);
    DrawWall(0.5, 1.7, 1.5, 1.7);
    DrawWall(-0.5, 2, 0.9, 2.1);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnd();
    glutSwapBuffers();
}

void DrawFloor(float x, float y, float z, float width, float length, float lift)
{
    float r = width/2;

    glVertex3d(x-r, y, z);

    glVertex3d(x+r, y, z);

    glVertex3d(x+r, y+lift, z+length);

    glVertex3d(x-r, y+lift, z+length);
}

void DrawWall(float x1, float z1, float x2, float z2){
    glTexCoord2f(0, 0);
    glVertex3f(x1, 0, z1);
    glTexCoord2f(1, 0);
    glVertex3f(x2, 0, z2);
    glTexCoord2f(1, 1);
    glVertex3f(x2, 0.7, z2);
    glTexCoord2f(0, 1);
    glVertex3f(x1, 0.7, z1);
}

void KeyPressed(unsigned char key, int x, int y){
    switch (key) {
    case 'w': { cam.MoveForward(); break; }
    case 's': { cam.MoveBack(); break; }
    case 'q': exit(0);
    }
    glutPostRedisplay();
}

void MouseMove(int x, int y)
{
    if(x>prev_mouse_x) cam.TurnRight();
    if(x<prev_mouse_x) cam.TurnLeft();

    if(y>prev_mouse_y) cam.view.y-=0.0005;
    if(y<prev_mouse_y) cam.view.y+=0.0005;

    glutPostRedisplay();
    prev_mouse_x = x;
    prev_mouse_y = y;
}

void Idle(){

}
