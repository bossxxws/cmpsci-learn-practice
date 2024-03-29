//#include <iostream>
//using namespace std;
////类模板与函数模板的区别
//template<class NameType,class AgeType = int>
//class Person
//{
//public:
//	Person(NameType name, AgeType age )
//	{
//		this->m_Name = name;
//		m_Age = age;//用不用this？没有命名冲突的情况下，可以省略this指针
//		//在成员函数中，当成员变量和参数名字相同时，可以使用 this 指针来区分它们。
//		//使用 this->m_Age 表示访问当前对象的成员变量 m_Age。
//	}
//	void showPerson()
//	{
//		cout << "name " << m_Name << endl;
//		cout << "age " << this->m_Age << endl;
//	}
//
//	NameType m_Name;
//	AgeType m_Age;
//
//};
////1、类模板没有自动类型推导方式
//void test01() 
//{
//	//Person p("孙悟空",999) 错误，无法用自动类型推导
//	Person<string, int>p("孙悟空", 1000);
//	p.showPerson();
//}
//
////2、类模板在模板参数列表中可以有默认参数
//void test02() 
//{
//	Person<string>p("猪八戒", 999);
//	p.showPerson();
//}
//int main()
//{
//	test01();
//	test02();
//
//	system("pause");
//
//	return 0;
//}