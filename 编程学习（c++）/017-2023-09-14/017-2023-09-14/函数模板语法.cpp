//#include <iostream>
//using namespace std;
////交换两个整型函数
//void swapInt(int& a, int& b) 
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
////交换两个浮点型的函数
//void swapDouble(double&a,double&b)
//{
//	double temp = a;
//	a = b;
//	b = temp;
//}
////函数模板
//template<typename T>
////声明一个模板，告诉编译器后面代码紧跟着的T不要报错
////T是一个通用数据类型
//void mySwap(T& a, T& b) 
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}
//
//void test01() 
//{
//	int a = 10;
//	int b = 20;
//	//swapInt(a, b);
//	//利用函数模板交换
//	//两种方式使用函数模板
//	//1、自动类型推导
//	mySwap(a, b);
//	//显示指定类型
//	mySwap<int>(a, b);
//	mySwap<int>(a, b);
//	cout << "a  =  " << a << "  b  =  " << b << endl;
//	double c = 1.1;
//	double d = 2.2;
//	mySwap(c, d);
//	mySwap<double>(c, d);
//	mySwap<double>(c, d);
//	//swapDouble(c, d);
//	cout << "c= " << c << " d= " << d << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//
//	return 0;
//}