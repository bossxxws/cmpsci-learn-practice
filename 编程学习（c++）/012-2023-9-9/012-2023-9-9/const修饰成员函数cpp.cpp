//#include <iostream>
//using namespace std;
////常函数
////成员函数后加const后我们称这个函数为常函数
////常函数内不可以修改成员属性
////this指针的本质 是指针常量 指针的指向是不可以修改的
////const Person * const this;
////在成员函数后面加const，修饰的是this指针，让指针指向的值也不可以修改
//class Person 
//{
//public:
//	void showPerson() const
//	{
//		this->m_B = 100;
//		
//		//this->m_A = 100;	
//		//this->NULL;//this指针是不可以修改指针的指向的
//	
//	}
//	void func()
//	{
//	}
//
//
//	int m_A;
//	mutable int m_B;//特殊变量，即使在常函数中也可以去修改这个值
//};
//int main()
//{
//	Person p;
//	
//	p.showPerson();
//	cout << p.m_B << endl;
//	
//	system("pause");
//
//	return 0;
//}
////常对象
//void test02() 
//{
//	const Person p;//在对象前加上const变成常对象
//	//p.m_A = 100;
//	p.m_B = 100;//m_B是特殊的值，在常对象下也可以修改
//	//常对象只能调用常函数
//	p.showPerson();
//	//p.func()    //常对象不可以调用普通成员函数，因为普通成员函数可以修改属性
//	
//
//}





