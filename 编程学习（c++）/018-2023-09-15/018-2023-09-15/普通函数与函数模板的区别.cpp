//#include <iostream>
//using namespace std;
////普通函数与函数模板的区别
//
////1、普通模板调用可以发生隐式类型转换
////2、函数模板 用自动类型推导 不可以发生隐式类型转换
////3、函数模板 用显示指定类型 可以发生隐式类型转换
//// 
////普通函数
//int myAdd01(int a, int b) 
//{
//	return a + b;
//}
//
////函数模板
//template<class T>
//T myAdd02(T a,T b) 
//{
//	
//	return a + b;
//
//	
//}
//void test01()
//{
//	int a = 10;
//	int b = 20;
//	char c = 'c';//a-97 c-99
//	cout << myAdd01(a, c) << endl;
//	//自动类型推导
//	//cout << myAdd02(a, c) << endl;//字符和整数运算时，把字符转换为对应的ASCii值进行运算
//	//显示指定类型
//	int k = myAdd02<int>(b, c);
//	cout << k << endl;
//	
//
//}
//int main()
//{
//	test01();
//	system("pause");
//
//	return 0;
//}