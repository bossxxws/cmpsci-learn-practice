#include <iostream>
using namespace std;
//类模板中成员函数创建时机
//类模板中成员函数在调用时才去创建
class Person1 
{
public:
	void showPerson1() 
	{
		cout << "Person1 show" << endl;
	}
};
class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2 show" << endl;
	}
};
template<class T>
class MyClass 
{
public:
	T obj;
	
	//类模板中的成员函数
	void func1() 
	{
		obj.showPerson1();
	}
	void func2()
	{
		obj.showPerson2();
	}
	//两个成员函数一开始创建不出来是因为obj无法确定数据类型
	//调用的时候T的类型确定了，才会创建出来
};
void test01() 
{
	MyClass<Person1>m;
	m.func1();
	//m.func2();
}


int main()
{
	test01();
	system("pause");

	return 0;
}