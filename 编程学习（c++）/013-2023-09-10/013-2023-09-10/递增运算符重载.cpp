//#include <iostream>
//using namespace std;
////���ص��������
////�Զ�������
//class MyInteger 
//{
//	friend ostream& operator<< (ostream& cout, MyInteger myint);
//public:
//	MyInteger() 
//	{
//		m_Num = 0;
//	}
//	//����++�����--ǰ��++�����  ����������Ϊ��һֱ��һ�����ݽ��в���
//	MyInteger& operator++() 
//	{
//		m_Num ++;
//		return *this;
//	}
//	//����++�����--����++�����
//	//void operator++(int) int����ռλ������������������ǰ�õ����ͺ��õ�����ռλ������int��������float ��double����ʹ
//	MyInteger& operator++(int)
//	{
//		
//		//��¼һ�µ�ʱ���
//		MyInteger temp = *this;
//		
//		//�����
//		
//		m_Num++;
//		//��󽫼�¼�Ľ������
//		return temp;
//
//	}
//private:
//	int m_Num;
//};
////������������� ---ԭ����������������Զ���Ķ��󣬱�������֪��������ʲô����֪����ô��������ʲô
//ostream& operator<< (ostream& cout, MyInteger myint) //����operator <<��cout,p��; ��cout<<p;
//{
//
//	cout << myint.m_Num;
//	return cout;
//
//}
//
//void test01() 
//{
//	MyInteger myint;
//	//��������++���������Ϊ��������֪����ô�ö��Զ�����������ͽ��е�������
//	cout << ++myint << endl;
//	cout << ++(++myint) << endl;
//
//}
//void test02() 
//{
//	MyInteger myint;
//	cout << myint++ << endl;
//	cout << myint << endl;
//
//}
//
//int main()
//{
//	test01();
//	test02();
//	system("pause");
//
//	return 0;
//}
