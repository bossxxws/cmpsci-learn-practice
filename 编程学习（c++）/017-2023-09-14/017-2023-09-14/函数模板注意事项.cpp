//#include <iostream>
//using namespace std;
//template<class T> //typename�����滻��class
//void mySwap(T&a,T&b) 
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}
////1���Զ����Ƶ��������Ƶ���һ�µ���������T�ſ���ʹ��
//void test01() 
//{
//	int a = 10;
//	int b = 20;
//	mySwap(a, b);//��ȷ
//	char c = 'c';
//	//mySwap(a, c);//����
//}
////2��ģ�����Ҫȷ����T���������ͣ��ſ���ʹ��
//template<class T>
//void func() 
//{
//	cout << "func����" << endl;
//
//}
//void test02() 
//{
//	func<int>();//ȷ����T���������� int ��������Ҳ���ԣ���㣩
//}
//int main()
//{
//	test02();
//
//	system("pause");
//
//	return 0;
//}