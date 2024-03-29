//#include <iostream>
//using namespace std;
//class Base 
//{
//public:
//	//纯虚函数
//	//只要有一个纯虚函数，这个类成为抽象类
//	//抽象类特点：
//	//1、无法实例化对象
//	//2、抽象类的子类 必须要重写父类中的纯虚函数 否则也属于抽象类
//	virtual void func() = 0;
//};
//class Son :public Base 
//{
//public:
//	virtual void func()
//	{
//		cout << "function函数的调用" << endl;
//	}
//};
//void test01() 
//{
//	
//	//Base b;//报错：不允许使用抽象类Base的对象（抽象类无法实例化对象）
//	//new Base;//抽象类无法实例化对象
//	
//	//Son s;//子类必须重写父类中的纯虚函数，否则也无法实例化对象
//	Base* base = new Son;//new的哪个对象，调用哪个对象里的函数
//	base->func();
//}
//int main()
//{
//	test01();
//
//	system("pause");
//
//	return 0;
//}