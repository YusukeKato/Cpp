/*
 * Cpp_game_001.cpp
 * Yusuke_Kato
 * 2016.5.21
 */
 
/*
 * OpenGL‚ğ—p‚¢‚½‚»‚ê
 * ‚â‚è•ûŠÔˆá‚Á‚Ä‚¢‚é‰Â”\«‚ª‚‚¢
 * display‚Ì’†‚Å‚â‚é‚Ì‚©
 * simu‚Æ‚©ì‚Á‚Ä‚»‚Á‚¿‚Å“®‚©‚·‚Ì‚©
 * ‚æ‚­‚í‚©‚ç‚È‚¢
 */
 
#include <GL/glut>
#include <iostream>
#include <windows>
using namespace std;

static GLint px = 0,py = 0;
static GLint nx = 40, ny = 40;

#define PI 3.14159265

void Point(int x,int y,float size){
	glPointSize(size);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}

void simu(void)
{
	if(ny > py) ny -= 8;
	else if(ny < py) ny += 8;
	if(nx > px) nx -= 8;
	else if(nx < px) nx += 8;
	if(ny == py && nx == px){
		cout << "\n\n ......END...... \n\n";
		exit(0);
	}
	Sleep(1000);
}

void display(void)
{
	int i, j;
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	for(j = -40; j <= 40; j += 8){
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glBegin(GL_LINES);
		glVertex2d(j,40);
		glVertex2d(j,-40);
		glVertex2d(40,j);
		glVertex2d(-40,j);
		glEnd();
		for(i = -40; i <= 40; i += 8){
			glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
			Point(j, i, 20);
		}//for_i
	}//for_j
	glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
	Point(px,py,15);//player
	glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
	Point(nx,ny,15);//enemy
	
	glFlush();
	
	simu();
	
	glutPostRedisplay();
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
	if ( key == 'w'){
		if(py < 40) py += 8;
	}
	if ( key == 's'){
		if(py > -40) py -= 8;
	}
	if ( key == 'd'){
		if(px < 40) px += 8;
	}
	if ( key == 'a'){
		if(px > -40) px -= 8;
	}
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