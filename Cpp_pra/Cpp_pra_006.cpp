/*
 * Cpp_pra_006.cpp
 */
 
/*
 * ‚·‚®–Y‚ê‚é
 */
#include <iostream>
using namespace std;

int main(void)
{
	int a;
	int b;
	int c;
	
	cout << "\n a : ";
	cin >> a;
	cout << "\n b : ";
	cin >> b;
	
	c = a + b;
	cout << "\n\n a + b = " << c;
	c = a - b;
	cout << "\n a - b = " << c;
	c = a * b;
	cout << "\n a * b = " << c;
	if(b == 0) exit(0);
	c = a / b;
	cout << "\n a / b = " << c;
	
	return 0;
}