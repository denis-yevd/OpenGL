#define STB_IMAGE_IMPLEMENTATION
#include <GL/glut.h>
#include <stb_image.h>
#include <iostream>
#include "point.h"
#include "camera.h"

int wnd_width=1300;
int wnd_height=900;
GLdouble aspect = wnd_width/wnd_height;
Camera cam;
unsigned int texture;
float text_coords[] = {0,0, 1,0, 1,1, 0,1};

void DrawFloor();
void DrawWall(float x, float width, float height);
void KeyPressed(int key, int x, int y);
void TextureInit();
void display();
void Idle();

void TextureInit(){
    int width, height, cnt;
    unsigned char* data = stbi_load("..//OpenGL/t.jpg", &width, &height, &cnt, 0);
    if(data==nullptr) std::cout<< "NO\n";
    else std::cout<<width<<'\t'<<height<<'\n';
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
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
    gluPerspective(90, aspect, 0.1, 3);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(cam.pos.x, cam.pos.y, cam.pos.z,
              cam.view.x, cam.view.y, cam.view.z,
              0, 0.5, 0);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    glBegin(GL_QUADS);
    DrawFloor();
    DrawWall(-0.5, 2, 0.7);
    DrawWall(0.5, 2, 0.7);
    glEnd();
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glutSwapBuffers();
}

void DrawFloor(){
    glTexCoord2f(0, 0);
    glVertex3d(1, 0, 2.5);
    glTexCoord2f(1, 0);
    glVertex3d(1, 0, 0);
    glTexCoord2f(1, 1);
    glVertex3d(-1, 0, 0);
    glTexCoord2f(0, 1);
    glVertex3d(-1, 0, 2.5);
}

void DrawWall(float x, float width, float height){
    glVertex3f(x, height, 0);
    glVertex3f(x, height, width);
    glVertex3f(x, 0, width);
    glVertex3f(x, 0, 0);
}

void KeyPressed(int key, int x, int y){
    switch (key) {
    case GLUT_KEY_UP: { cam.MoveForward(); break; }
    case GLUT_KEY_DOWN: { cam.MoveBack(); break; }
    case GLUT_KEY_LEFT: {cam.TurnLeft(); break; }
    case GLUT_KEY_RIGHT: {cam.TurnRight(); break; }
    }
    cam.PrintPosition();
    glutPostRedisplay();
}

void Idle(){

}
