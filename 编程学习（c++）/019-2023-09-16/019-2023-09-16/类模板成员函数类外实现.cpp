//#include <iostream>
//using namespace std;
////类模板成员函数类外实现
//template<class T1,class T2>
//class Person 
//{
//public:
//	Person(T1 name, T2 age);//构造函数
//	//{
//	//	m_Name = name;
//	//	m_Age = age;
//	//}
//	void showPerson();
//	/*{
//		cout << "姓名 " << m_Name << "年龄 " << m_Age << endl;
//	}*/
//	T1 m_Name;
//	T2 m_Age;
//};
////构造函数的类外实现
//template<class T1,class T2>
//Person<T1, T2>::Person(T1 name, T2 age) //加上模板的参数列表来表示这是个模板
//{
//	m_Name = name;
//	m_Age = age;
//}
//template<class T1, class T2>
//void Person<T1, T2>::showPerson() 
//{
//	cout << "姓名 " << m_Name << "年龄 " << m_Age << endl;
//}
//void test01() 
//{
//	Person<string, int>p("Tom", 20);
//	cout << p.m_Name <<" "<< p.m_Age << endl;
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