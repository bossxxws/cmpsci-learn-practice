//#include <iostream>
//using namespace std;
//class Person
//{
//public:
//	Person(int age)
//	{
//		m_Age = new int(age);//�ɳ���Ա�ֶ����٣��ֶ��ͷ�
//
//
//	}
//	~Person() 
//	{
//		if (m_Age != NULL) 
//		{
//			delete m_Age;
//			m_Age = NULL;
//		}
//	}
//	//���� ��ֵ�����
//	Person& operator=(Person& p) 
//	{
//		//�������ṩǳ����
//		//m_Age = p.m_Age;
//		//���ж��Ƿ��������ڶ���������У����ͷŸɾ���Ȼ�������
//		if (m_Age != NULL) 
//		{
//			delete m_Age;
//			m_Age = NULL;
//		}
//		m_Age = new int(*p.m_Age);//new�������¿ռ䣬()�����ŵ�������
//		return *this;
//	}
//
//	int* m_Age;//������д��ָ��
//};
//
//void test01() 
//{
//	Person p1(18);
//	Person p2(20);
//	Person p3(30);
//	p3 = p2 = p1;//��ֵ����
//	cout << "p1�ĵ�ַ�� " << p1.m_Age << endl;
//	cout << "p1�����ó��ĵ����䣺 " << *p1.m_Age << endl;
//	cout << "p2�����ó��ĵ����䣺 " << *p1.m_Age << endl;
//	cout << "p3�����ó��ĵ����䣺 " << *p3.m_Age << endl;
//}
//int main()
//{
//	test01();
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	c = b = a;
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//	system("pause");
//
//	return 0;
//}