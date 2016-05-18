/*
 * Cpp_pra_003.cpp
 * Yusuke_Kato
 * 2016.5.18
 */
 
#include <iostream>
#include <time>
using namespace std;

int Answer(void)
{
	srand((unsigned int)time(NULL));
	return rand()%100 + 1;
}

void Input(int *input_num)
{
	cout << " Input : ";
	cin >> *input_num;
}

int NumIf(int input_num, int answer)
{
	int result = 0;
	
	if(input_num == answer){
		cout << "\n\nWWWWWWWWWWWWWWW\n";
		cout << " !!Great!!\n";
		cout << "MMMMMMMMMMMMMMM\n\n";
		result = 1;
	} if(input_num > answer - 5 && input_num < answer + 5){
		cout << " regrettable\n";
	} if(input_num < answer){
		cout << " input_num < answer\n";
	} if(input_num > answer){
		cout << " input_num > answer\n";
	}
	
	return result;
}

void Times(int i)
{
	cout << "\n---------------\n";
	cout << " " << i << " times\n";
}

int Times_if(int i)
{
	if(i >= 5)
		return 1;
	return 0;
}

void End(int answer)
{
	cout << "\n=====\n";
	cout << " " << answer;
	cout << "\n=====\n";
	cout <<"\n\n END\n\n";
}

int main(void)
{
	int answer;
	int input_num;
	int i;
	int result = 0;
	int result2 = 0;
	
	answer = Answer();
	
	for(i = 1; result == 0 && result2 == 0; i++){
		Times(i);
		Input(&input_num);
		result = NumIf(input_num, answer);
		result2 = Times_if(i);
	}//for
	End(answer);
}