//#include <iostream>
//using namespace std;
//template<class T> //typename可以替换成class
//void mySwap(T&a,T&b) 
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}
////1、自动型推导，必须推导出一致的数据类型T才可以使用
//void test01() 
//{
//	int a = 10;
//	int b = 20;
//	mySwap(a, b);//正确
//	char c = 'c';
//	//mySwap(a, c);//错误
//}
////2、模板必须要确定出T的数据类型，才可以使用
//template<class T>
//void func() 
//{
//	cout << "func调用" << endl;
//
//}
//void test02() 
//{
//	func<int>();//确定出T的数据类型 int （其他的也可以，随便）
//}
//int main()
//{
//	test02();
//
//	system("pause");
//
//	return 0;
//}