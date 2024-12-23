//#include <iostream>
//using namespace std;
//
////通过全局函数来打印Person信息
//
////提前让编译器知道Person类存在
//template<class T1, class T2>
//class Person;
////类外实现
//template<class T1, class T2>
//void printPerson2(Person<T1, T2> p) //函数模板的实现
//{
//	cout << "类外实现-----姓名 " << p.m_Name << " 年龄 " << p.m_Age << endl;
//}
//
//template<class T1,class T2>
//class Person 
//{
//	//全局函数    类内实现
//	friend void printPerson(Person<T1,T2>a p) 
//	{
//		cout << "姓名 " << p.m_Name << " 年龄 " << p.m_Age << endl;
//	}
//
//	//全局函数     类外实现
//	//friend void printPerson2(Person<T1, T2> p); //普通函数的声明,与函数模板的实现不配套
//	//加空模板参数列表
//	//如果全局函数时类外实现，需要让编译器提前知道这个函数的存在
//	friend void printPerson2<>(Person<T1, T2> p);//函数模板的声明
//public:
//	Person(T1 name,T2 age) 
//	{
//		m_Name = name;
//		m_Age = age;
//	}
//	
//private:
//	T1 m_Name;
//	T2 m_Age;
//};
//
//
//
//
//
////全局函数在类内实现的测试
//void test01() 
//{
//	Person<string, int>p("Tom", 20);
//	printPerson(p);
//}
//
////全局函数在类外实现的测试
//void test02() 
//{
//	Person<string, int>p("Jerry", 20);
//	printPerson2(p);
//}
//
//
//int main()
//{
//	test01();
//	test02();
//	system("pause");
//
//	return 0;
//}