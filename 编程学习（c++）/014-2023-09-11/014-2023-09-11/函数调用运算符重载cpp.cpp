//#include <iostream>
//using namespace std;
////函数调用运算符重载
////打印输出类
//class Myprint 
//{
//public:
//	//重载函数调用运算符
//	void operator()(string test) //重载小括号
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
//	myprint("Hello World");//由于使用起来类似于函数调用，因此被称为仿函数
//	Myprint02("Hello C++");
//}
////仿函数非常灵活，没有固定的写法
////加法类
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
//	//匿名函数对象   当前行被执行，立即被释放
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