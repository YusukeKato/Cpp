/*
 * Cpp_pra_002.cpp
 * Yusuke_Kato
 * 2016.5.15
 */
 
/*
 * �����ăQ�[��
 */

#include <iostream>
using namespace std;

int main(void)
{
	int inNum = 0;
	int seikai;
	
	seikai = rand()%100 + 1;//����
	
	while(1){
		cout << '\n' << ' ' << " ���́F";
		cin >> inNum;
		if(inNum == seikai){
			cout << '\n' << ' ' << "�I�I�����I�I" << '\n';
			break;
		}//if
		if(inNum >= seikai-5 && inNum <= seikai+5)
			cout << '\n' << ' ' << "������" <<'\n';
		if(inNum > seikai)
			cout << ' ' << "�������傫��" << '\n';
		if(inNum < seikai)
			cout << ' ' << "������菬����" << '\n';
	}//while_big
	return 0;
}