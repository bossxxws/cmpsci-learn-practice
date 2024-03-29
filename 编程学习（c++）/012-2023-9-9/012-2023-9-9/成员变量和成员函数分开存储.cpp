//#include <iostream>
//using namespace std;
////只有非静态成员变量才属于类的对象上
////成员变量 和 成员函数 是分开存储的
//class Person 
//{
//	int m_A;//非静态成员变量，属于类的对象上
//	static int m_B;//静态成员变量 不属于类的对象上；第三次输出的大小仍位4
//	void func() {}//非静态成员函数，和成员变量分开存储的，不属于类的对象上
//};	static void func02(){}//静态成员函数，不属于类的对象上
//void test01() 
//{	
//	Person p;
//	//空对象占用内存空间为：1
//	//c++编译器会给每个空对象也分配一个字节空间，是为了区分对象占内存的位置
//	//每个空对象也应该有一个独一无二的内存地址
//	cout << sizeof(p) << endl;
//}
//void test02() 
//{
//	Person p;
//	cout << "Size of p: " << sizeof(p) << endl;
//}
//int main()
//{
//	test01();//空对象：1
//	test02();//有了int m_A之后就不是空对象了，大小为int的大小4
//	system("pause");
//
//	return 0;
//}