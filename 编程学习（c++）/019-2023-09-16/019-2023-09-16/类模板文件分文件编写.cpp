//#include <iostream>
//using namespace std;
//#include"Person.hpp"//包含复包含
////类模板文件分文件编写
////把一个类单独写在一个文件中
////.h中写类的声明
////.cpp里写成员函数的实现
//
////创建实际问题导致错误
////1、第一种解决方式，直接包含源文件
// 
//
////2、第二种解决方式，将.h和.cpp的内容写到一起，将后缀名改为.hpp文件
////hpp一看就是类模板（约定俗成的名称，都写成它，不是强制的）
//
//
////template<class T1, class T2>
////class Person
////{
////public:
////	Person(T1 name, T2 age);
////	/*{
////		m_Name = name;
////		m_Age = age;
////
////	}*/
////	void showPerson();
////	T1 m_Name;
////	T2 m_Age;
////
////};
////template<class T1,class T2>//让编译器认识一下
////Person<T1, T2>::Person(T1 name, T2 age) 
////{
////	m_Name = name;
////	m_Age = age;
////
////}
////template<class T1, class T2>
////void Person<T1,T2>::showPerson() 
////{
////	cout << m_Age << " " << m_Name << endl;
////
////}
//void test01() 
//{
//	Person<string, int>p("Tom", 18);
//	p.showPerson();
//}
//
//int main()
//{
//	test01();
//	system("pause");
//
//	return 0;
//}