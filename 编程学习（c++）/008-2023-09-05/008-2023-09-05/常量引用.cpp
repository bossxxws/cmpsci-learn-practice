//#include <iostream>
//using namespace std;
//
//int main()
//{
//	//常量引用
//	//使用后惨景：修饰形参，防止误操作
//	int a = 10;
//	//int &  ref = 10是错误的，引用必须引用一块合法的内存空间
//	int& ref = a;//正确的
//	const int& ref = 10;//加上const之后编译器将代码修改为int temp  = 10；const int & ref = temp；（这样语法是合法的）
//	//temp空间是找不到的，是编译器申请的
//	
//
//
//	system("pause");
//
//	return 0;
//}