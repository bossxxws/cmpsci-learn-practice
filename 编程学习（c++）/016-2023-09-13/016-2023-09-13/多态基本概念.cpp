//#include <iostream>
//using namespace std;
//class Animal 
//{
//public:
//	//虚函数
//	virtual void speak() 
//	{
//		cout << "动物在说话" << endl;
//	}
//};
////猫类
//class Cat :public Animal
//{
//public:
//	//virtual 可省略
//	virtual void speak() 
//	{
//		cout << "小猫在说话" << endl;
//	}
//};
////狗类
//class Dog :public Animal 
//{
//public:
//	void speak() 
//	{
//		cout << "小狗在说话 ：你个狗" << endl;
//	}
//};
////执行说话的函数
////地址早绑定 在编译阶段就确定了函数的地址
////如果想执行让猫说话，那么这个函数的地址就不能提前绑定，需要在运行阶段进行绑定
////也就是地址晚绑定
//
////动态多态满足条件
////1.有继承关系
////2.子类要重写父类的虚函数（子类中virtual可省略，父类中的不可省略）
//
////动态多态使用
////父类的指针或者引用 执行子类对象
//void dospeak(Animal& animal)
//{
//	animal.speak();
//}
//void test01() 
//{
//	Cat cat;
//	dospeak(cat);
//
//}
//void test02()
//{
//	Dog dog;
//	dospeak(dog);
//
//}
//void test03()
//{
//	cout << "size of Animal  "<<sizeof(Animal)<< endl;
//
//}
//int main()
//{
//	test01();
//	test02();
//	test03();
//
//	system("pause");
//
//	return 0;
//}