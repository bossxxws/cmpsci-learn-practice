//#include <iostream>
//using namespace std;
//class Person 
//{
//	friend ostream& operator<< (ostream& cout, Person& p);
//public:
//	Person(int a, int b) 
//	{
//		m_A = a;
//		m_B = b;
//	}
//private:
//	////成员函数重载 行不通-----因为无法实现cout在左侧
//	// void operator<<(cout)
//	// {
//	// 
//	// 
//	// 
//	// }
//	//p.operator<<(cout) 简化版本p<<cout;
//	
//	int m_A;
//	int m_B;
//	
//};
////只能运用全局函数重载左移运算符
////cout ostream 输出流 o = out，输出，stream = 流
//ostream& operator<< (ostream& cout, Person& p) //本质operator <<（cout,p）; 简化cout<<p;
//{
//
//	cout << "m_A = " << p.m_A << "m_B = " << p.m_B << endl;
//	return cout;
//
//}
//void test01()
//{
//	Person p(10, 10);
//	
//	
//	cout << p << "hello world" << endl<< " ssss " << endl;
//
//}
//
//
//
//int main()
//{
//	test01();
//
//	system("pause");
//
//	return 0;
//}