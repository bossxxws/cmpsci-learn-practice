//#include <iostream>
//using namespace std;
//#include<string>
////�������ʹ�������
//
//class Animal 
//{
//public:
//	Animal()
//	{
//		cout << "Animal���캯������" << endl;
//	}
//	/*virtual ~Animal() 
//	{
//		cout << "Animal��������������" << endl;
//	}*/
//	//�������������Խ�� ����ָ���ͷ��������ʱ���ɾ�������
//	virtual ~Animal() = 0;
//	//�������� ��Ҫ����Ҳ��Ҫʵ��
//	//���˴�������֮�� �����Ҳ���ڳ����� �޷�ʵ��������
//	//���麯��
//	virtual void speak() = 0;
//};
//Animal::~Animal() 
//{
//	cout << "Animal�Ĵ���������������" << endl;
//};
//class Cat :public Animal 
//{
//public:
//	Cat(string name) 
//	{
//		cout << "Cat���캯������" << endl;
//		m_Name = new string(name);
//	}
//	virtual void speak() 
//	{
//		cout << *m_Name<<"Сè��˵��" << endl;
//
//	}
//	string* m_Name;
//	~Cat() 
//	{
//		if (m_Name != NULL) 
//		{
//			cout << "Cat������������" << endl;
//			delete m_Name;
//			m_Name = NULL;
//			
//		}
//	}
//};
//void test01()
//{
//	Animal* animal = new Cat("Tom");
//	animal->speak();
//	//����ָ��������ʱ�����������������������
//	//������������ж��������ݣ�������ڴ��й¶���
//	delete animal;
//}
//int main()
//{
//	test01();
//	system("pause");
//
//	return 0;
//}