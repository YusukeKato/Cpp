/*
 * Cpp_pra_002.cpp
 * Yusuke_Kato
 * 2016.5.15
 */
 
/*
 * 数あてゲーム
 */

#include <iostream>
using namespace std;

int main(void)
{
	int inNum = 0;
	int seikai;
	
	seikai = rand()%100 + 1;//乱数
	
	while(1){
		cout << '\n' << ' ' << " 入力：";
		cin >> inNum;
		if(inNum == seikai){
			cout << '\n' << ' ' << "！！正解！！" << '\n';
			break;
		}//if
		if(inNum >= seikai-5 && inNum <= seikai+5)
			cout << '\n' << ' ' << "おしい" <<'\n';
		if(inNum > seikai)
			cout << ' ' << "正解より大きい" << '\n';
		if(inNum < seikai)
			cout << ' ' << "正解より小さい" << '\n';
	}//while_big
	return 0;
}