//#include <iostream>
//using namespace std;
//
////ͨ��ȫ�ֺ�������ӡPerson��Ϣ
//
////��ǰ�ñ�����֪��Person�����
//template<class T1, class T2>
//class Person;
////����ʵ��
//template<class T1, class T2>
//void printPerson2(Person<T1, T2> p) //����ģ���ʵ��
//{
//	cout << "����ʵ��-----���� " << p.m_Name << " ���� " << p.m_Age << endl;
//}
//
//template<class T1,class T2>
//class Person 
//{
//	//ȫ�ֺ���    ����ʵ��
//	friend void printPerson(Person<T1,T2>a p) 
//	{
//		cout << "���� " << p.m_Name << " ���� " << p.m_Age << endl;
//	}
//
//	//ȫ�ֺ���     ����ʵ��
//	//friend void printPerson2(Person<T1, T2> p); //��ͨ����������,�뺯��ģ���ʵ�ֲ�����
//	//�ӿ�ģ������б�
//	//���ȫ�ֺ���ʱ����ʵ�֣���Ҫ�ñ�������ǰ֪����������Ĵ���
//	friend void printPerson2<>(Person<T1, T2> p);//����ģ�������
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
////ȫ�ֺ���������ʵ�ֵĲ���
//void test01() 
//{
//	Person<string, int>p("Tom", 20);
//	printPerson(p);
//}
//
////ȫ�ֺ���������ʵ�ֵĲ���
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