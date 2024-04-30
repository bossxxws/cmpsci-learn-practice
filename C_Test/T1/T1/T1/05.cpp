#include<iostream>

using namespace std;

int main()
{
	int var1 = 41;
	int var2 = 14;
	int* ptr1 = &var1;
	int* ptr2 = &var2;

	*ptr1 = var1 + 14;
	*ptr2 = *ptr1 + 5;

	ptr1 = ptr2;

	var1 = *ptr1 + *ptr2;

	cout << var1 << " " << var2;
	//cout << endl << ptr1;

	return 0;
}