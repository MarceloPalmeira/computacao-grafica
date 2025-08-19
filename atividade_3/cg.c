//
//  main.m
//  TransformacaoPlanetas
//
//  Created by Marcelo Costa on 15/12/12.
//  Copyright (c) 2012 Universidade Federal de Alagoas - UFAL. All rights reserved.
//

//#import <Cocoa/Cocoa.h>
//#import <GLUT/GLUT.h>


//#include <iostream>
#include <GL/glut.h>

static int year = 0, day = 0;

// Inicializa parâmetros de rendering
void init(void){
	glClearColor (0.0, 0.0, 0.0, 0.0);
}

// Função callback chamada para fazer o desenho
void display(void){
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);
    
	glPushMatrix();
        glRotatef ((GLfloat) year, 1.0, 0.0, 0.0);
        glRotatef ((GLfloat) day, 0.0, 0.0, 1.0);
        glutWireSphere(1.0, 20, 16);   /* desenha o sol */
	glPopMatrix();
    
	glPushMatrix();
        glRotatef ((GLfloat) year, 0.0, 1.0, 0.0);
        glTranslatef (2.0, 0.0, 0.0); //Translada a partir do novo sistema de coordenadas resultante da Rotacao
        glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
        glutWireSphere(0.2, 10, 8);    /* desenha um planeta */
	glPopMatrix();

	// Executa os comandos OpenGL
    // glFlush();
    
	glutSwapBuffers(); //substitui o Flush quando usamos o GLUT_DOUBLE
}


void reshape (int w, int h){
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    
	gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
	gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); //posicao da camera
    
}

void keyboard (unsigned char key, int x, int y){
	switch (key) {
        case 'd':
            day = (day + 10) % 360;  //% valor do resto
            glutPostRedisplay(); //Redesenha a cena com novas coordenadas, é executado no glutMainLoop;
            break;
        case 'D':
            day = (day - 10) % 360;
            glutPostRedisplay();
            break;
        case 'y':
            year = (year + 5) % 360;
            glutPostRedisplay();
            break;
        case 'Y':
            year = (year - 5) % 360;
            glutPostRedisplay();
            break;
        default:
            break;
	}
}

int main(int argc, char** argv){
	
    glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow("Rotacao de Planetas");
	
    init();
	glutDisplayFunc(display); // Usada para (re)desenhar a cena
	glutReshapeFunc(reshape); //Usar sempre que existe alteração no tamanho da Janela e ajuste da Viewport
	glutKeyboardFunc(keyboard);
	glutMainLoop();

return 0;

}