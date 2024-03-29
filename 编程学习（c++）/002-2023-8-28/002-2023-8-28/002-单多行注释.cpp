#include <iostream>
using namespace std;
#define Day 7 //常量定义方法1
int main()
{
/*
这是
多行
注释
*/

	cout << "Hello C++" << endl; //输出Hello C++  - 这是单行注释
	int a = 10;
	cout << "a = " << a << endl;
	system("pause");
	cout << "一周有" << Day << "天" << endl;
	system("pause");
	const int month = 12;//常量定义方法2
	cout << month << endl;
	float k = 4e5;// 4 * 10**5
	float j = 3e-2; //3*10-2
	cout << j << endl;
	cout << k << endl;
	int h = 0;
	cin >> h;
	cout << h << endl;
	float l = 3.14f;
	cin >> l;
	cout << l << endl;
	system("pause");
	return 0;
}