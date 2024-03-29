#include <iostream>
using namespace std;
//继承同名静态成员处理方式
class Base
{
public:

	static int m_A;
	static void func()
	{
		cout << "f" << endl;
	}
	static void func(int a)
	{
		cout << "f" << endl;
	}
};
int Base::m_A = 100051;
class Son : public Base
{
public:
	static void func()
	{
		cout << "s" << endl;
	}
	static int m_A;

};
int Son::m_A = 200;
void test01()
{
	//通过对象访问
	cout << "通过对象访问" << endl;
	Son s;
	cout << "Son_m_A = " << s.m_A << endl;
	cout << "Base_m_A = " << s.Base::m_A << endl;
	//通过类名访问
	cout << "通过类名访问" << endl;
	cout << "Son_m_A = " << Son::m_A << endl;
	//第一个：：代表通过类名方式访问，第二个：：代表访问父类作用域下的m_A
	cout << "Base_m_A = " << Son::Base::m_A << endl;




	//自己摸索的，可行？
	cout << "Base_m_A = " << Base::m_A << endl;



}
void test02()
{
	//通过对象访问
	Son s;
	s.func();
	s.Base::func();
	//通过类名访问
	Son::func();
	Son::Base::func();
	Son::Base::func(100);
}
int main()
{
	test01();
	test02();
	system("pause");

	return 0;
}