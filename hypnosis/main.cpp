#include <iostream>
#include <GLUT/glut.h>
#include <cmath>
int i;
int Sub_Menu;
float x,y,z,w;
float angle,angle1,theta=0 ;


void spiral()
{
    z = 0.0;
    w = 0.0;
    for(i = 0 ;i < 3600; i++)
    {
        x=w*(cos(z * 3.14 / 180.0));
        y=w*(sin(z * 3.14 / 180.0));
        glBegin(GL_POINTS);
        glVertex2f(x,y);
        glEnd();
        z = z + 1.0;
        w = 0.1 * z / 360;
       glRotatef(theta, 0, 0, 1);
        
        
    }
   // glRotatef(theta, 0, 0, 1);
}


void test(){
    theta -=0.0000001;
    glutPostRedisplay();
    
}
void test1(){
    theta -=0.0000001;
    glutPostRedisplay();
    
}

void keyboard(unsigned char key, int x, int y)
{
    
    if (key=='a' || key == 'A'){
        
        theta=theta-1.0;
        glutIdleFunc(test);
    }
    if (key=='d' || key == 'D'){
        theta=theta+1.0;
        glutIdleFunc(test1);
        
    }

    
    if (key=='s')
        glutIdleFunc(NULL);
    
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f (0.35,1,1);
    
    spiral();
   /* glRotatef(theta,0,0,1);
    glutWireTeapot(1.0);*/
    
    glutSwapBuffers();
    glFlush();
}
void init()
{
    glClearColor(0,0,0,0.0);
    glColor3f(0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.4,1.4,-1.4,1.4);
    
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0.0, 0.0);
    glutCreateWindow("hypnosis");
    //glutIdleFunc(test);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    init();
    glutMainLoop();
    
    
}