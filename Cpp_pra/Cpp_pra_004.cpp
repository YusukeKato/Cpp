/*
 * C_pra_004.cpp
 * Yusuke_Kato
 * 2016.5.19
 */
 
#include <iostream>
using namespace std;

int func_1(int i)
{
	int inputNum;
	
	cout << "----------\n";
	cout << " " << i << " times\n";
	cout << " Input Number >> ";
	cin >> inputNum;
	return inputNum;
}

int main(void)
{
	int num = 0;
	int i;
	
	for(i = 1;num != i * 100; i++){
	
		num += func_1(i);
	
		cout << "----------\n";
		cout << " num << " << num << "\n";
	}
	
	return 0;
}