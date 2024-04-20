#include<iostream>

using namespace std;

int main()
{
	int var1 = 14;
	int var2 = 44;
	int* ptr1 = &var1;

	var1 = *ptr1 + var2;

	var2 = 5;

	ptr1 = &var2;
	*ptr1 = 2;
	var1 = var1 + var2;

	cout << var1 << " " << var2;
	cout << endl << ptr1;

}