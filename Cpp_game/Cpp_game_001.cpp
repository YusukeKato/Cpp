/*
 * Cpp_game_001.cpp
 * Yusuke_Kato
 * 2016.5.21
 * 2016.5.22
 */
 
/*
 * OpenGLを用いたそれ
 * ・やり方間違っている可能性が高い
 *   displayの中でやるのか
 *   simuとか作ってそっちで動かすのか
 *   よくわからない
 * 
 * ・（解決した）flagを用いてターンを作った
 *	 ターン制にするにはどうすればいいか
 * 	 自分が動いて、相手が動いて、というような順番を作る方法を考える
 */
 
#include <GL/glut>
#include <iostream>
#include <windows>//Sleepを使いたかった
using namespace std;

static GLint px = 0,py = 0;//player位置
static GLint nx = 40, ny = 40;//enemy位置

static GLint flag = 0;//flagターンを作るため

#define PI 3.14159265//円周率

/* 点を作る。要素は（x座標、y座標、大きさ） */
void Point(int x,int y,float size){
	glPointSize(size);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}

/* enemyの動き */
void enemy_motion(void)
{
	if(flag == 1){
		if(ny > py) ny -= 8;
		else if(ny < py) ny += 8;
		if(nx > px) nx -= 8;
		else if(nx < px) nx += 8;
		if(ny == py && nx == px){
			cout << "\n\n ......END...... \n\n";
			exit(0);
		}
		Sleep(1000);//なくてもいい
		flag = 0;//ターンの切り替えのため
	}//if_flag
}

void display(void)
{
	int i, j;
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	/* field作成 : -40～40に間隔8ずつ */
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
	/* player描写 */
	glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
	Point(px,py,15);//player
	/* enemy描写 */
	glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
	Point(nx,ny,15);//enemy
	
	glFlush();
	
	enemy_motion();
	
	glutPostRedisplay();
}//display

/* よくわからない */
void resize(int w, int h)
{
	glViewport( 0, 0, w, h );
 	glMatrixMode(GL_PROJECTION);
 	glLoadIdentity();
 	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
 	glMatrixMode(GL_MODELVIEW);
 	glLoadIdentity();
}//resize

/* これから使うかも */
void mouse(int button, int state, int x, int y)
{
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
		if(py < 40){
			py += 8;
			flag = 1;
		}//if_py
	}//if_key
	if ( key == 's'){
		if(py > -40){
			py -= 8;
			flag = 1;
		}//if_py
	}//if_key
	if ( key == 'd'){
		if(px < 40){
			px += 8;
			flag = 1;
		}//if_px
	}//if_key
	if ( key == 'a'){
		if(px > -40){
			px -= 8;
			flag = 1;
		}//if_px
	}//if_key
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