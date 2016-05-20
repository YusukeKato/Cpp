/*
 * C_pra_005.cpp
 * Yusuke_Kato
 * 2016.5.20
 */
 
/*
 * gameAIの勉強
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
	
	/* 初期化 */
	for(j = 0; j < 10; j++){
		for(i = 0; i < 10; i++){
			field[j][i] = 0;
		}
	}
	
	while(ny != py || nx != px){//playerとenemyが同じ場所になったら終了
		field[py][px] = 0;//playerの前の場所を０に戻す
		field[ny][nx] = 0;//enemyの前の場所を０に戻す
		/* player移動 */
		cout << "\n w-up, s-down, d-right, a-left \n";
		cout << " Input >> ";
		c = getchar();//入力
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
		Sleep(1000);//1s止める
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
		field[py][px] = 2;//playerを配置
		field[ny][nx] = 3;//enemy配置
		/* 表示 */
		system("cls");//まっさら
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