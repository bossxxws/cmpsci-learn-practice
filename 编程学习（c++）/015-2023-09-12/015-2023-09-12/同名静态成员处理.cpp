#include <iostream>
using namespace std;
//�̳�ͬ����̬��Ա����ʽ
class Base
{
public:

	static int m_A;
	static void func()
	{
		cout << "f" << endl;
	}
	static void func(int a)
	{
		cout << "f" << endl;
	}
};
int Base::m_A = 100051;
class Son : public Base
{
public:
	static void func()
	{
		cout << "s" << endl;
	}
	static int m_A;

};
int Son::m_A = 200;
void test01()
{
	//ͨ���������
	cout << "ͨ���������" << endl;
	Son s;
	cout << "Son_m_A = " << s.m_A << endl;
	cout << "Base_m_A = " << s.Base::m_A << endl;
	//ͨ����������
	cout << "ͨ����������" << endl;
	cout << "Son_m_A = " << Son::m_A << endl;
	//��һ����������ͨ��������ʽ���ʣ��ڶ�������������ʸ����������µ�m_A
	cout << "Base_m_A = " << Son::Base::m_A << endl;




	//�Լ������ģ����У�
	cout << "Base_m_A = " << Base::m_A << endl;



}
void test02()
{
	//ͨ���������
	Son s;
	s.func();
	s.Base::func();
	//ͨ����������
	Son::func();
	Son::Base::func();
	Son::Base::func(100);
}
int main()
{
	test01();
	test02();
	system("pause");

	return 0;
}