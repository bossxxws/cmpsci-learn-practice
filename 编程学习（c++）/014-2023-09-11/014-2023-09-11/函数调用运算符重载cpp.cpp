//#include <iostream>
//using namespace std;
////�����������������
////��ӡ�����
//class Myprint 
//{
//public:
//	//���غ������������
//	void operator()(string test) //����С����
//	{
//		cout << test << endl;
//	}
//};
//void Myprint02(string test)
//{
//	cout << test << endl;
//}
//void test01() 
//{
//	Myprint myprint;
//	
//	myprint("Hello World");//����ʹ�����������ں������ã���˱���Ϊ�º���
//	Myprint02("Hello C++");
//}
////�º����ǳ���û�й̶���д��
////�ӷ���
//class Myadd 
//{
//public:
//	int operator()(int num1,int num2)
//	{
//		return num1 + num2;
//	}
//};
//void test02() 
//{
//	Myadd myadd;
//	int ret = myadd(100,100);
//	cout << ret << endl;
//
//	//������������   ��ǰ�б�ִ�У��������ͷ�
//	cout << Myadd()(100, 100) << endl;
//}
//
//
//int main()
//{
//	test01();
//	test02();
//	system("pause");
//
//	return 0;
//}