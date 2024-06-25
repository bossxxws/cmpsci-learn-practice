#include<iostream>

using namespace std;

int main()
{

	int a = 1, b = 2, c = 3;

	int* d;

	b = a;

	a = c;

	d = &a;

	*d = b;

	cout << *d;

	return 0;
}