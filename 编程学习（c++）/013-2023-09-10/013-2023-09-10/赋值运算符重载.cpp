//#include <iostream>
//using namespace std;
//class Person
//{
//public:
//	Person(int age)
//	{
//		m_Age = new int(age);//由程序员手动开辟，手动释放
//
//
//	}
//	~Person() 
//	{
//		if (m_Age != NULL) 
//		{
//			delete m_Age;
//			m_Age = NULL;
//		}
//	}
//	//重载 赋值运算符
//	Person& operator=(Person& p) 
//	{
//		//编译器提供浅拷贝
//		//m_Age = p.m_Age;
//		//先判断是否有属性在堆区，如果有，先释放干净，然后再深拷贝
//		if (m_Age != NULL) 
//		{
//			delete m_Age;
//			m_Age = NULL;
//		}
//		m_Age = new int(*p.m_Age);//new开辟了新空间，()里面存放的是数据
//		return *this;
//	}
//
//	int* m_Age;//把年龄写成指针
//};
//
//void test01() 
//{
//	Person p1(18);
//	Person p2(20);
//	Person p3(30);
//	p3 = p2 = p1;//赋值操作
//	cout << "p1的地址： " << p1.m_Age << endl;
//	cout << "p1解引用出的的年龄： " << *p1.m_Age << endl;
//	cout << "p2解引用出的的年龄： " << *p1.m_Age << endl;
//	cout << "p3解引用出的的年龄： " << *p3.m_Age << endl;
//}
//int main()
//{
//	test01();
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	c = b = a;
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//	system("pause");
//
//	return 0;
//}