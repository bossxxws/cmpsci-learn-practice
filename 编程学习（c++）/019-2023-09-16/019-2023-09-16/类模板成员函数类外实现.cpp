//#include <iostream>
//using namespace std;
////��ģ���Ա��������ʵ��
//template<class T1,class T2>
//class Person 
//{
//public:
//	Person(T1 name, T2 age);//���캯��
//	//{
//	//	m_Name = name;
//	//	m_Age = age;
//	//}
//	void showPerson();
//	/*{
//		cout << "���� " << m_Name << "���� " << m_Age << endl;
//	}*/
//	T1 m_Name;
//	T2 m_Age;
//};
////���캯��������ʵ��
//template<class T1,class T2>
//Person<T1, T2>::Person(T1 name, T2 age) //����ģ��Ĳ����б�����ʾ���Ǹ�ģ��
//{
//	m_Name = name;
//	m_Age = age;
//}
//template<class T1, class T2>
//void Person<T1, T2>::showPerson() 
//{
//	cout << "���� " << m_Name << "���� " << m_Age << endl;
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