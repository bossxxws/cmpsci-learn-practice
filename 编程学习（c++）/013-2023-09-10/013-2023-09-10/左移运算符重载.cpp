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
//	////��Ա�������� �в�ͨ-----��Ϊ�޷�ʵ��cout�����
//	// void operator<<(cout)
//	// {
//	// 
//	// 
//	// 
//	// }
//	//p.operator<<(cout) �򻯰汾p<<cout;
//	
//	int m_A;
//	int m_B;
//	
//};
////ֻ������ȫ�ֺ����������������
////cout ostream ����� o = out�������stream = ��
//ostream& operator<< (ostream& cout, Person& p) //����operator <<��cout,p��; ��cout<<p;
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