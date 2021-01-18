#include <GL/glut.h>
#include <glm/vec2.hpp>
#include <math.h>
#include <iostream>

int wnd_width=1300;
int wnd_height=900;
float pos_x=0, pos_z=0;
float view_x=0, view_y=0, view_z=0.1;
float angle = 90;
float radius = 0.1;
GLdouble aspect = wnd_width/wnd_height;

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
    case GLUT_KEY_UP: {
        pos_x += radius * cos(3.14*angle/180);
        pos_z += radius * sin(3.14*angle/180);
        radius+=0.1;
        break;
    }
    case GLUT_KEY_DOWN: {
        pos_x = radius*cos(angle);
        pos_z = radius*sin(angle);
        radius-=0.1;
        break;
    }
    case GLUT_KEY_LEFT: {
        angle -= 5;
        view_x = radius * cos(3.14 * angle/180);
        view_z = radius * sin(3.14 * angle/180);
        break;
    }
    case GLUT_KEY_RIGHT: {
        angle += 5;
        view_x = radius * cos(3.14 * angle/180);
        view_z = radius * sin(3.14 * angle/180);
        break;
    }
    }
    std::cout<<"x: "<<pos_x<<'\t';
    std::cout<<"z: "<<pos_z<<'\n';
    glutPostRedisplay();
}

void display(){
    glClearColor(0.6, 0.8, 1., 1.);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90, aspect, 0.1, 3);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(pos_x, 0.2, pos_z,
              view_x, 0.2, view_z,
              0, 0.2, 0);

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
