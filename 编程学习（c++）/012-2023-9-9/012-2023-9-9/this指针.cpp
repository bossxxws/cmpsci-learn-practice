//#include <iostream>
//using namespace std;
////������Ƴ�ͻ
////���ض�������*this
//class Person 
//{
//public:
//	Person(int age) 
//	{	//������Ƴ�ͻ
//		this->age = age;
//		//this ָ��ָ����Ǳ����õĳ�Ա���������Ķ���
//	}
//	int age;
//	Person& PersonAddAge(Person& p) 
//	{
//		this->age += p.age;
//		//this��ָ��p2��ָ�룬������*thisָ��p2�ı���
//		return *this;
//	}
//};
//void test01() 
//{
//	Person p1(18);
//	cout << "p1������Ϊ�� " << p1.age << endl;
//
//}
//void test02() 
//{
//	Person p1(10);
//	Person p2(10);
//	//��ʽ���˼��
//	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
//	cout << "p2�������ǣ� " << p2.age << endl;
//}
//int main()
//{
//	test01();
//	test02();
//	system("pause");
//
//	return 0;
//}