//#include <iostream>
//using namespace std;
//class Person
//{
//public:
//	static void func()
//	{
//		
//		m_A = 100;//静态成员函数可以访问静态成员变量
//		//m_B = 200;  //静态成员函数不可以访问非静态成员变量，无法区分到底是哪个对象的m_B属性
//		cout << "static void 函数调用" << endl;
//	}
//	static int m_A;
//	int m_B;
//private:
//	static void func2() 
//	{
//		cout << "func2的调用" << endl;
//	}
//};
//
//void test01()
//{	//通过对象访问
//	Person p;
//	p.func();
//	//通过类名访问
//	Person::func();
//	
//}
//void test02() 
//{
//	Person p;
//	//静态成员函数也是有访问权限的
//	p.func2();
//}
//
//
//int main()
//{	
//	Person p;
//	test01();
//	system("pause");
//
//	return 0;
//}