//#include <iostream>
//using namespace std;
//class Base 
//{
//public:
//	//���麯��
//	//ֻҪ��һ�����麯����������Ϊ������
//	//�������ص㣺
//	//1���޷�ʵ��������
//	//2������������� ����Ҫ��д�����еĴ��麯�� ����Ҳ���ڳ�����
//	virtual void func() = 0;
//};
//class Son :public Base 
//{
//public:
//	virtual void func()
//	{
//		cout << "function�����ĵ���" << endl;
//	}
//};
//void test01() 
//{
//	
//	//Base b;//����������ʹ�ó�����Base�Ķ��󣨳������޷�ʵ��������
//	//new Base;//�������޷�ʵ��������
//	
//	//Son s;//���������д�����еĴ��麯��������Ҳ�޷�ʵ��������
//	Base* base = new Son;//new���ĸ����󣬵����ĸ�������ĺ���
//	base->func();
//}
//int main()
//{
//	test01();
//
//	system("pause");
//
//	return 0;
//}