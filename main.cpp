#include "Functions.h"

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(wnd_width, wnd_height);
    glutInitWindowPosition(300, 100);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glutCreateWindow("OpenGL my");
    glutDisplayFunc(display);
    //glutIdleFunc(Idle);
    glutKeyboardFunc(KeyPressed);
    glutPassiveMotionFunc(MouseMove);
    glutSetCursor(GLUT_CURSOR_CROSSHAIR);
    TextureInit("..//OpenGL/t.jpg");

    glutMainLoop();
    return 0;
}
