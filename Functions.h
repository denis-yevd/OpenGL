#include <GL/glut.h>
#include "point.h"
#include "camera.h"

int wnd_width=1300;
int wnd_height=900;
GLdouble aspect = wnd_width/wnd_height;
Camera cam;

void DrawFloor(){
    glVertex3d(1, 0, 2.5);
    glVertex3d(1, 0, 0);
    glVertex3d(-1, 0, 0);
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

    glBegin(GL_QUADS);
    glColor3f(0, 0, 0.7);
    DrawFloor();
    glColor3f(0, 0.8, 0.1);
    DrawWall(-0.5, 2, 0.7);
    DrawWall(0.5, 2, 0.7);
    glEnd();
    glutSwapBuffers();
}

void Idle(){

}
