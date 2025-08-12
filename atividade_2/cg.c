#include <GL/glut.h>
#include <stdlib.h> 

static float angulo = 0.0f; 
void initPicole(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500.0, 0, 500.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void desenhaPetalaDireta(int x0, int y0, int x1, int y1, int x2, int y2, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
        glVertex2i(x0, y0);
        glVertex2i(x1, y1);
        glVertex2i(x2, y2);
    glEnd();
}

void picoleFunc(void){
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex2i(248, 250);
        glVertex2i(251, 250);
        glVertex2i(251, 100);
        glVertex2i(248, 100);
    glEnd();

    glPushMatrix();                        
    glTranslatef(250.0f, 250.0f, 0.0f);     
    glRotatef(angulo, 0.0f, 0.0f, 1.0f);    
    glTranslatef(-250.0f, -250.0f, 0.0f);   

    desenhaPetalaDireta(250, 250, 230, 200, 270, 200, 1.0, 0.0, 0.0);
    desenhaPetalaDireta(250, 250, 300, 230, 300, 270, 1.0, 1.0, 0.0);
    desenhaPetalaDireta(250, 250, 230, 300, 270, 300, 0.0, 1.0, 0.0);
    desenhaPetalaDireta(250, 250, 200, 230, 200, 270, 0.0, 0.0, 1.0);

    glPopMatrix(); 

    glFlush();
}

void timer(int value){
    angulo += 10.0f; 

    if (angulo >= 360.0f) angulo -= 360.0f;

    glutPostRedisplay();
    glutTimerFunc(70, timer, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Picolé");

    initPicole();
    glutDisplayFunc(picoleFunc);
    glutTimerFunc(70, timer, 0);

    glutMainLoop();
}
