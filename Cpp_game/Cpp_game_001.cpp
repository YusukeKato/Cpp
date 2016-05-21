/*
 * Cpp_game_001.cpp
 * Yusuke_Kato
 * 2016.5.21
 */
 
/*
 * OpenGL‚ð—p‚¢‚½‚»‚ê
 */
 
#include <GL/glut>
#include <iostream>
using namespace std;

static GLint flag = 0;

#define PI 3.14159265

void Point(int x,int y,float size){
 glPointSize(size);
 glBegin(GL_POINTS);
 glVertex2i(x,y);
 glEnd();
}

void display(void)
{
	int i, j, k;
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	for(j = -40; j <= 40; j += 8){
		for(i = -40; i <= 40; i += 8){
			glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
			Point(j, i, 20);
			glBegin(GL_LINES);
			glVertex2d(j,40);
			glVertex2d(j,-40);
			
			glVertex2d(40,j);
			glVertex2d(-40,j);
			glEnd();
		}//for_i
	}//for_j
	
	glFlush();
}//display

void resize(int w, int h)
{
	glViewport( 0, 0, w, h );
 	glMatrixMode(GL_PROJECTION);
 	glLoadIdentity();
 	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
 	glMatrixMode(GL_MODELVIEW);
 	glLoadIdentity();
}//resize

void mouse(int button, int state, int x, int y)
{
	static int x0, y0;
	
	switch (button) {
		case GLUT_LEFT_BUTTON:
			break;
		case GLUT_MIDDLE_BUTTON:
			break;
		case GLUT_RIGHT_BUTTON:
			break;
		default:
			break;
	}
}//mouse

void keyboard(unsigned char key ,int x, int y)
{
	if ( key == '\x1b') exit(0);
	if ( key == 'w') flag = 1;
	if ( key == 's') flag = 2;
	if ( key == 'd') flag = 3;
	if ( key == 'a') flag = 4;
}//keyboard

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
}//init

int main(int argc, char *argv[])
{
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 640);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	init();
	glutMainLoop();
	return 0;
}//main