//#include <iostream>
//using namespace std;
//class Person 
//{
//public:
//	//1.���ж��󶼹���һ������
//	//2.����׶ξͷ����ڴ�
//	//3.���������������ʼ������
//	static int m_A;
//private:
//	static int m_B;
//	//��̬��Ա����Ҳ���з���Ȩ�޵�
//};
//int Person::m_A = 100;
//int Person::m_A = 300;
//void test01()
//{
//	Person p;
//	cout << p.m_A << endl;
//	Person p2;
//	p2.m_A = 200;
//	cout << p.m_A << endl;
//	cout << p2.m_A << endl;
//}
//void test02()
//{
//	Person p;
//	//��̬��Ա���� ������ĳ�������� ���ж�����ͬһ������
//	//��˾�̬��Ա���������ַ��ʷ�ʽ
//	//ͨ��������з���
//	cout << p.m_A << endl;
//	//ͨ���������з���
//	cout << Person::m_A << endl;
//	
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