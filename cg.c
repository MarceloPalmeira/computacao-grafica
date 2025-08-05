#include <GL/glut.h> 

void initPicole(void){

	glClearColor(0.0, 0.0, 0.0, 0.0);

	gluOrtho2D(0.0, 500.0, 0, 500.0);

}

void desenhaPetala(float r, float g, float b){
	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
		glVertex2i(250, 250);
		glVertex2i(230, 200);
		glVertex2i(270, 200);
	glEnd();
}

void picoleFunc(void){

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, .0, .0);
	glBegin(GL_POLYGON);
		glVertex2i(248, 250);
		glVertex2i(251, 250);
		glVertex2i(248, 100);
		glVertex2i(251,100);
	glEnd();	

	for(int i = 0; i < 4; i++)
	{
		float angula = i * 90.0f;
		glPushMatrix();
		glTranslatef(250.0f, 250.0f, 0.0f);
		glRotatef(angula, 0.0f, 0.0f, 1.0f);
		glTranslatef(-250.0f, -250.0f, 0.0f);

		// Cores do catavento: vermelho, amarelo, verde, azul
		float r = 0.0f, g = 0.0f, b = 0.0f;
		if (i == 0) { r = 1.0f; g = 0.0f; b = 0.0f; }      // vermelho
		if (i == 1) { r = 1.0f; g = 1.0f; b = 0.0f; }      // amarelo
		if (i == 2) { r = 0.0f; g = 1.0f; b = 0.0f; }      // verde
		if (i == 3) { r = 0.0f; g = 0.0f; b = 1.0f; }      // azul

		desenhaPetala(r, g, b);
	
		glPopMatrix();
	}

	glFlush();
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Picole");

	initPicole();

	glutDisplayFunc(picoleFunc);


	glutMainLoop();	
}
