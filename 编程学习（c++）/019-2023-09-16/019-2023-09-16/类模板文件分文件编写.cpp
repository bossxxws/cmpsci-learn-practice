//#include <iostream>
//using namespace std;
//#include"Person.hpp"//����������
////��ģ���ļ����ļ���д
////��һ���൥��д��һ���ļ���
////.h��д�������
////.cpp��д��Ա������ʵ��
//
////����ʵ�����⵼�´���
////1����һ�ֽ����ʽ��ֱ�Ӱ���Դ�ļ�
// 
//
////2���ڶ��ֽ����ʽ����.h��.cpp������д��һ�𣬽���׺����Ϊ.hpp�ļ�
////hppһ��������ģ�壨Լ���׳ɵ����ƣ���д����������ǿ�Ƶģ�
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
////template<class T1,class T2>//�ñ�������ʶһ��
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