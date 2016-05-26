/*
 * Cpp_game_0004.cpp
 * Yusuke_Kato
 * 2016.5.21
 * 2016.5.26
 */
 
/*
 * OpenGL
 */
 
/*
 * player:�ǂ�������i�蓮�j
 * enemy:������i�����j
 * 
 * �ł��Ă͂���
 */
 
/*
 * ����L�[�i�W�j
 * w:��
 * s:��
 * d:�E
 * a:��
 * e:�E��
 * q:����
 * x:�E��
 * z:����
 */
 
#include <GL/glut>
#include <iostream>
#include <windows>
#include <time>
using namespace std;

#define Y_MAX 40
#define Y_MIN -40
#define X_MAX 40
#define X_MIN -40
#define STEP 8//�ړ��̊Ԋu�A�}�X��
#define ENEMY_NONE 24//����Ƃ��̋�������Ă�����G�͋C�ɂ��Ȃ�

static GLint px = X_MIN,py = Y_MIN;//player�ʒu
static GLint nx = X_MAX,ny = Y_MAX;//enemy�ʒu

static GLint flag = 0;//�����Ƒ��肪���݂ɓ�������

/* �_�����B�v�f�́ix���W�Ay���W�A�傫���j */
void Point(int x,int y,float size){
	glPointSize(size);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}

/* ����̓����i�����j */
void enemy_motion(void)
{	
	int dy,dx;//�����Ƒ���̋����̍�(���ƕ����l����)(��Βlfabs)
	int w_dy_p,w_dy_m,w_dx_p,w_dx_m;//�ǂ���̋���
	int copy_py, copy_px;//�ړ�����O�̍��W��ۑ����Ă���
	int random;//��������
	
	if(flag == 0 || flag == 1){
		copy_py = py;//���ʂ������瓮���Ȃ������Ƃ������Ƃ𔻒f���邽��
		copy_px = px;
		/* player��enemy�̋��� */
		dy = py - ny;//�ʒu�ɂ���Đ������ς��
		dx = px - nx;//��Βl�Ƃ����肵�Ă��g��
		/* player�ƕǂ̋��� */
		//w:wall,p:plus,m:minus
		w_dy_p = Y_MAX - py;//�ォ��̋���p:plus,m:minus
		w_dy_m = py - Y_MIN;//������
		w_dx_p = X_MAX - px;//�E����
		w_dx_m = px - X_MIN;//������
		/********** ���� **********/
		/**************************/
		/* ���肪�߂��ɂ͂��Ȃ��Ƃ��A�܂����S�֌����� */
		if(fabs(dy) >= ENEMY_NONE && fabs(dx) >= ENEMY_NONE){
			if(py >= 0) py -= STEP;
			else if(py < 0) py += STEP;
			if(px >= 0) px -= STEP;
			else if(px < 0) px += STEP;
		}
		/* ���肪�߂��Ƃ��͍L���ق��֓����� */
		else {
			if(py == ny){//�����P
				if(w_dy_p >= w_dy_m)py += STEP;
				else if(w_dy_p < w_dy_m)py -= STEP;
			}else if(px == nx){//�����Q
				if(w_dx_p >= w_dx_m) px += STEP;
				else if(w_dx_p < w_dx_m) px -= STEP;
			}else if(py > ny && px > nx){//�����R
				if(w_dy_m >= w_dx_m){
					py -= STEP;
					px += STEP;
				}
				else if(w_dy_m < w_dx_m){
					py += STEP;
					px -= STEP;
				}
			}else if(py > ny && px < nx){//�����S
				if(w_dy_m >= w_dx_p){
					py -= STEP;
					px -= STEP;
				}
				else if(w_dy_m < w_dx_p){
					py += STEP;
					px += STEP;
				}
			}else if(py < ny && px > nx){//�����T
				if(w_dy_p >= w_dx_m){
					py += STEP;
					px += STEP;
				}
				else if(w_dy_p < w_dx_m){
					py -= STEP;
					px -= STEP;
				}
			}else if(py < ny && px < nx){//�����U
				if(w_dy_p >= w_dx_p){
					py += STEP;
					px -= STEP;
				}
				else if(w_dy_p < w_dx_p){
					py -= STEP;
					px += STEP;
				}
			}
		}
		/**************************/
		/**************************/
		if(py == ny && px == nx){
			cout << "\n END \n";
			exit(0);
		}
		Sleep(1000);
		if(flag == 0) flag = 1;
		else if(flag == 1) flag = 2;
	}//if_flag
}

void display(void)
{
	int i, j;
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	/* field�쐬 : -40�`40�ɊԊu8���� */
	for(j = -40; j <= 40; j += STEP){
		glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
		glBegin(GL_LINES);
		glVertex2d(j,40);//��
		glVertex2d(j,-40);
		glVertex2d(40,j);//�c
		glVertex2d(-40,j);
		glVertex2d(j,40);//�΁F�E�ォ�獶���F����
		glVertex2d(-40,-j);
		glVertex2d(40,j);//�΁F�E�ォ�獶���F�E��
		glVertex2d(-j,-40);
		glVertex2d(40,j);//�΁F���ォ��E���F�E��
		glVertex2d(j,40);
		glVertex2d(-40,j);//�΁F���ォ��E���F����
		glVertex2d(j,-40);
		glEnd();
	}//for_j
	for(j = -40; j <= 40; j += STEP){
		for(i = -40; i <= 40; i += STEP){
			glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
			Point(j,i,20);
		}//for_i
	}//for_j
	/* player�`�� */
	glColor4f(0.2f, 0.6f, 0.3f, 0.2f);
	Point(px,py,15);//player
	/* enemy�`�� */
	glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
	Point(nx,ny,15);//enemy
	
	glFlush();
	
	enemy_motion();
	
	glutPostRedisplay();
}//display

/* �悭�킩��Ȃ� */
void resize(int w, int h)
{
	glViewport( 0, 0, w, h );
 	glMatrixMode(GL_PROJECTION);
 	glLoadIdentity();
 	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
 	glMatrixMode(GL_MODELVIEW);
 	glLoadIdentity();
}//resize

void keyboard(unsigned char key ,int x, int y)
{
	if ( key == '\x1b') exit(0);
	if ( key == 'w'){
		if(ny < 40){
			if(flag == 2){
				ny += STEP;
				flag = 0;
			}
		}//if_py
	}//if_key
	if ( key == 's'){
		if(ny > -40){
			if(flag == 2){
				ny -= STEP;
				flag = 0;
			}
		}//if_py
	}//if_key
	if ( key == 'd'){
		if(nx < 40){
			if(flag == 2){
				nx += STEP;
				flag = 0;
			}
		}//if_px
	}//if_key
	if ( key == 'a'){
		if(nx > -40){
			if(flag == 2){
				nx -= STEP;
				flag = 0;
			}
		}//if_px
	}//if_key
	if ( key == 'e'){
		if(ny < 40 && nx < 40){
			if(flag == 2){
				ny += STEP;
				nx += STEP;
				flag = 0;
			}
		}//if_px
	}//if_key
	if ( key == 'q'){
		if(ny < 40 && nx > -40){
			if(flag == 2){
				ny += STEP;
				nx -= STEP;
				flag = 0;
			}
		}//if_px
	}//if_key
	if ( key == 'x'){
		if(ny > -40 && nx < 40){
			if(flag == 2){
				ny -= STEP;
				nx += STEP;
				flag = 0;
			}
		}//if_px
	}//if_key
	if ( key == 'z'){
		if(ny > -40 && nx > -40){
			if(flag == 2){
				ny -= STEP;
				nx -= STEP;
				flag = 0;
			}
		}//if_px
	}//if_key
}//keyboard

void init(void)
{
	glClearColor(1.0, 0.5, 0.5, 1.0);
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
	glutKeyboardFunc(keyboard);
	init();
	glutMainLoop();
	return 0;
}//main