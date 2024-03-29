#include <iostream>
using namespace std;
#include<string>

//string的构造函数

void test01() 
{
	string s1;//默认构造
	const char* s = "hello world";
	string s2(s);//使用字符串s初始化
	cout << "s2 =  " << s2 << endl;
	string s3(s2);//拷贝构造
	cout << "s3 " << s3 << endl;
	string s4(10, 'a');//使用n个字符串初始化
	cout << " " << s4 << endl;
}
int main()
{
	test01();
	system("pause");

	return 0;
}