#include <GL/glut.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  GLfloat x, y, z;
} Vec3;

static float year = 0, day = 0;
static bool animacao_ativa = false;
static float vel_orbita = 0.02f;
static float vel_rotacao = 0.05f;

static void init(void) {
  glClearColor(0, 0, 0, 0);
  glEnable(GL_DEPTH_TEST);
}

static void drawStar(void) {
  glPushMatrix();
    glRotatef((GLfloat)day, 0, 1, 0);
    glRotatef(90, 1, 0, 0);
    glutWireSphere(1, 20, 16); // Sol
  glPopMatrix();
}

static void drawPlanet(Vec3 pos, bool retrograde) {
  glPushMatrix();
    glRotatef((GLfloat)(retrograde ? -year : year), 0, 1, 0); 
    glTranslatef(pos.x, pos.y, pos.z);
    glRotatef((GLfloat)day, 0, 1, 0); 
    glRotatef(90, 1, 0, 0);
    glutWireSphere(0.25, 10, 8); 
  glPopMatrix();
}

static void drawMoon(Vec3 primaryPos, bool primaryRetrograde, Vec3 pos, Vec3 tlAxis) {
  glPushMatrix();
    glRotatef((GLfloat)(primaryRetrograde ? -year : year), 0, 1, 0);
    glTranslatef(primaryPos.x, primaryPos.y, primaryPos.z);

    glRotatef((GLfloat)year, tlAxis.x, tlAxis.y, tlAxis.z);
    glTranslatef(pos.x, pos.y, pos.z);

    glutWireSphere(0.08, 10, 8);
  glPopMatrix();
}

static void display(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glColor3f(1, 1, 0);
  drawStar();

  Vec3 planet1Pos = {.x = 1.8f, .y = 0.0f, .z = 0};
  glColor3f(0.0f, 0.5f, 1.0f);
  drawPlanet(planet1Pos, false);

  Vec3 planet2Pos = {.x = 2.5f, .y = 0.0f, .z = 0};
  glColor3f(1.0f, 0.3f, 0.0f);
  drawPlanet(planet2Pos, true);

  Vec3 moon1Pos = {.x = 0.5f, .y = 0.0f, .z = 0};
  Vec3 moon1TlAxis = {.x = 1, .y = 0, .z = 0}; 
  glColor3f(0.8f, 0.8f, 0.8f);
  drawMoon(planet2Pos, true, moon1Pos, moon1TlAxis);

  Vec3 moon2Pos = {.x = 0.7f, .y = 0.0f, .z = 0};
  Vec3 moon2TlAxis = {.x = 0, .y = 0, .z = 1}; 
  glColor3f(0.5f, 0.5f, 0.5f);
  drawMoon(planet2Pos, true, moon2Pos, moon2TlAxis);

  glutSwapBuffers();
}

static void handleReshape(int w, int h) {
  glViewport(0, 0, w, h);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60, (GLfloat)w / (GLfloat)h, 1, 20);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0, 2, 6, 0, 0, 0, 0, 1, 0);
}

static void idle(void) {
  if (animacao_ativa) {
    year = fmod(year + vel_orbita, 360.0f);
    day  = fmod(day  + vel_rotacao, 360.0f);
    glutPostRedisplay();
  }
}

static void handleKeyboard(unsigned char key, int x, int y) {
  (void)x;
  (void)y;

  switch (key) {
  case 'Y':
  case 'y':
    animacao_ativa = !animacao_ativa;
    if (animacao_ativa)
      glutIdleFunc(idle);
    else
      glutIdleFunc(NULL);
    break;
  case 27: 
    exit(0);
  default:
    break;
  }
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(600, 600);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Translacao de Planetas e Luas");

  init();
  glutDisplayFunc(display);
  glutReshapeFunc(handleReshape);
  glutKeyboardFunc(handleKeyboard);

  glutMainLoop();
  return EXIT_SUCCESS;
}
