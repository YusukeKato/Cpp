/*
 * C_pra_005.cpp
 * Yusuke_Kato
 * 2016.5.20
 */
 
/*
 * gameAI�̕׋�
 */
 
#include <iostream>
#include <windows.h>
using namespace std;

int main(void)
{
	int i, j;
	int c;
	int px = 0, py = 0;//player_position
	int nx = 9, ny = 9;//enemy_position
	
	int field[10][10];
	
	/* ������ */
	for(j = 0; j < 10; j++){
		for(i = 0; i < 10; i++){
			field[j][i] = 0;
		}
	}
	
	while(ny != py || nx != px){//player��enemy�������ꏊ�ɂȂ�����I��
		field[py][px] = 0;//player�̑O�̏ꏊ���O�ɖ߂�
		field[ny][nx] = 0;//enemy�̑O�̏ꏊ���O�ɖ߂�
		/* player�ړ� */
		cout << "\n w-up, s-down, d-right, a-left \n";
		cout << " Input >> ";
		c = getchar();//����
		switch(c){
			case 'w':
				if(py > 1) py -= 2;
				break;
			case 's':
				if(py < 8) py += 2;
				break;
			case 'd':
				if(px < 8) px += 2;
				break;
			case 'a':
				if(px > 1) px -= 2;
				break;
			default:
				break;
		}
		Sleep(1000);//1s�~�߂�
		if(ny < py){
			ny++;
		} else if(ny > py){
			ny--;
		}
		if(nx < px){
			nx++;
		} else if(nx > px){
			nx--;
		}
		field[py][px] = 2;//player��z�u
		field[ny][nx] = 3;//enemy�z�u
		/* �\�� */
		system("cls");//�܂�����
		for(j = 0; j < 10; j++){
			cout << "\n";
			for(i = 0; i < 10; i++){
				cout << field[j][i];
			}
		}
		cout << "\n";
	}
	cout << "\n END \n";
}