//#include <iostream>
//using namespace std;
//class Animal 
//{
//public:
//	//�麯��
//	virtual void speak() 
//	{
//		cout << "������˵��" << endl;
//	}
//};
////è��
//class Cat :public Animal
//{
//public:
//	//virtual ��ʡ��
//	virtual void speak() 
//	{
//		cout << "Сè��˵��" << endl;
//	}
//};
////����
//class Dog :public Animal 
//{
//public:
//	void speak() 
//	{
//		cout << "С����˵�� �������" << endl;
//	}
//};
////ִ��˵���ĺ���
////��ַ��� �ڱ���׶ξ�ȷ���˺����ĵ�ַ
////�����ִ����è˵������ô��������ĵ�ַ�Ͳ�����ǰ�󶨣���Ҫ�����н׶ν��а�
////Ҳ���ǵ�ַ���
//
////��̬��̬��������
////1.�м̳й�ϵ
////2.����Ҫ��д������麯����������virtual��ʡ�ԣ������еĲ���ʡ�ԣ�
//
////��̬��̬ʹ��
////�����ָ��������� ִ���������
//void dospeak(Animal& animal)
//{
//	animal.speak();
//}
//void test01() 
//{
//	Cat cat;
//	dospeak(cat);
//
//}
//void test02()
//{
//	Dog dog;
//	dospeak(dog);
//
//}
//void test03()
//{
//	cout << "size of Animal  "<<sizeof(Animal)<< endl;
//
//}
//int main()
//{
//	test01();
//	test02();
//	test03();
//
//	system("pause");
//
//	return 0;
//}