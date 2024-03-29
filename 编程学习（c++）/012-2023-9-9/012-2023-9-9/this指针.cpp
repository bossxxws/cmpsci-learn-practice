//#include <iostream>
//using namespace std;
////解决名称冲突
////返回对象本身用*this
//class Person 
//{
//public:
//	Person(int age) 
//	{	//解决名称冲突
//		this->age = age;
//		//this 指针指向的是被调用的成员函数所属的对象
//	}
//	int age;
//	Person& PersonAddAge(Person& p) 
//	{
//		this->age += p.age;
//		//this是指向p2的指针，解引用*this指向p2的本体
//		return *this;
//	}
//};
//void test01() 
//{
//	Person p1(18);
//	cout << "p1的年龄为： " << p1.age << endl;
//
//}
//void test02() 
//{
//	Person p1(10);
//	Person p2(10);
//	//链式编程思想
//	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
//	cout << "p2的年龄是： " << p2.age << endl;
//}
//int main()
//{
//	test01();
//	test02();
//	system("pause");
//
//	return 0;
//}