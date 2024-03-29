//#include <iostream>
//using namespace std;
//class Person 
//{
//public:
//	int m_A;
//	int m_B;
//	//通过成员函数重载加号
//	//Person operator+(Person& p) 
//	//{
//	//	Person temp;
//	//	temp.m_A = this->m_A + p.m_B;//this指向person p自己的值
//	//	temp.m_B = this->m_B + p.m_B;
//	//	return temp;
//	//}
//	
//
//};
////通过全局函数重载+号
//Person operator+ (Person & p1, Person & p2) 
//{
//	Person temp;
//	temp.m_A = p1.m_A + p2.m_A;
//	temp.m_B = p1.m_B + p2.m_B;
//	return temp;
//}
////函数重载版本
//Person operator+ (Person& p1, int number)
//{
//	Person temp;
//	temp.m_A = p1.m_A + number;
//	temp.m_B = p1.m_B + number;
//	return temp;
//}
//void test01() 
//{
//	Person p1;
//	p1.m_A = 10;
//	p1.m_B = 10;
//	Person p2;
//	p2.m_A = 10;
//	p2.m_B = 10;
//	//成员函数本质的调用
//	//Person p3 = p1.operator+(p2);
//	//全局函数重载的本质调用
//	//Person p3 = operator+(p1,p2);
//	Person p3 = p1 + p2;
//	//运算符重载 也可以发生函数重载
//	Person p4 = p1 + 100; //Person + int
//	cout << "p3.m_A = : " << p3.m_A << endl;
//	cout << "p3.m_B = : " << p3.m_B << endl;
//	cout << "p4.m_A = : " << p4.m_A << endl;
//	cout << "p4.m_B = : " << p4.m_B << endl;
//
//}
//int main()
//{
//	test01();
//
//	system("pause");
//
//	return 0;
//}