//#include <iostream>
//using namespace std;
////��̬�İ���2-������Ʒ
//class AbstractDrinking 
//{
//public:
//	//��ˮ
//	virtual void Boil() = 0;
//	//����
//	virtual void Brew() = 0;
//	//���뱭��
//	virtual void PourCup() = 0;
//	//���븨��
//	virtual void PutSomething() = 0;
//	//������Ʒ
//	void makeDrink()
//	{
//		Boil();
//		Brew();
//		PourCup();
//		PutSomething();
//	}
//};
////��������
//class Coffee :public AbstractDrinking 
//{
//public:
//	//��ˮ
//	virtual void Boil() 
//	{
//		cout << "��ũ��ɽȪ" << endl;
//	}
//	virtual void Brew() 
//	{
//		cout << "���ݿ���" << endl;
//	}
//	//���뱭��
//	virtual void PourCup() 
//	{
//		cout << "���뱭��" << endl;
//	}
//	//���븨��
//	virtual void PutSomething() 
//	{
//		cout << "����ţ��" << endl;
//	}
//	//������Ʒ
//	
//};
//class Tea :public AbstractDrinking 
//{
//public:
//	//��ˮ
//	virtual void Boil()
//	{
//		cout << "��ũ��ɽȪ" << endl;
//	}
//	virtual void Brew()
//	{
//		cout << "���ݿ���" << endl;
//	}
//	//���뱭��
//	virtual void PourCup()
//	{
//		cout << "���뱭��" << endl;
//	}
//	//���븨��
//	virtual void PutSomething()
//	{
//		cout << "�������" << endl;
//	}
//};
//void doWork(AbstractDrinking* abs)
//{
//	abs->makeDrink();
//	delete abs;//�ͷ�
//}
//void test01() 
//{
//	//��������
//	doWork(new Coffee);//AbstractDrinking* abs = new Coffee
//	
//}
//void test02() 
//{
//	doWork(new Tea);//AbstractDrinking* abs = new Tea
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