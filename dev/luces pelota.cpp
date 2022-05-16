#include <GL/freeglut.h>
void display() {
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);

glPushMatrix();
//glTranslatef(0.75, 0.0, -1.0);
glutSolidSphere(2.0, 30, 30);
glPopMatrix();
glPopMatrix();
glFlush();
glutSwapBuffers();
}
void reshape(GLint w, GLint h) {
glViewport(0, 0, w, h);
glMatrixMode(GL_PROJECTION);
GLfloat aspect = GLfloat(w) / GLfloat(h);
glLoadIdentity();
if (w <= h) {
// el ancho es más pequeño, así que estira la altura
glOrtho(-2.5, 2.5, -2.5/aspect, 2.5/aspect, -10.0, 10.0);
} else {
// la altura es más pequeña, así que estira el ancho
glOrtho(-2.5*aspect, 2.5*aspect, -2.5, 2.5, -10.0, 10.0);
}
}
void init() {
	
GLfloat black[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat yellow[] = { 1.0, 1.0, 0.0, 0.0 };
GLfloat cyan[] = { 0.0, 1.0, 1.0, 1.0 };
GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };

GLfloat direction[] = { 0.0, 1.0, 0.0, 0.0 };
GLfloat direction1[] = { -1.0, -1.0, -1.0, 0.0 };
GLfloat direction2[] = { 1.0, -1.0, -1.0, 0.0 };


GLfloat mat_ambient[] = { 0.329412f, 0.223529f, 0.027451f,1.0f };

//glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cyan);
//glMaterialfv(GL_FRONT, GL_SPECULAR, white);
glMaterialf(GL_FRONT, GL_SHININESS, 30);
glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);

//glLightfv(GL_LIGHT0, GL_AMBIENT, black);
glLightfv(GL_LIGHT0, GL_DIFFUSE, cyan);
//glLightfv(GL_LIGHT0, GL_SPECULAR, white);
glLightfv(GL_LIGHT0, GL_POSITION, direction);

glLightfv(GL_LIGHT1, GL_DIFFUSE, yellow);

glLightfv(GL_LIGHT1, GL_POSITION, direction1);

glLightfv(GL_LIGHT2, GL_DIFFUSE, white);

glLightfv(GL_LIGHT2, GL_POSITION, direction2);



glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_LIGHT1);
glEnable(GL_LIGHT2);
glEnable(GL_DEPTH_TEST);
}
int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
glutInitWindowPosition(80, 80);
glutInitWindowSize(800, 600);
glutCreateWindow("Formas en luz amarilla");
glutReshapeFunc(reshape);
glutDisplayFunc(display);
init();
glutMainLoop();
return 0;
}
