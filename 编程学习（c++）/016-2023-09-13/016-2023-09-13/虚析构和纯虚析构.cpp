//#include <iostream>
//using namespace std;
//#include<string>
////虚析构和纯虚析构
//
//class Animal 
//{
//public:
//	Animal()
//	{
//		cout << "Animal构造函数调用" << endl;
//	}
//	/*virtual ~Animal() 
//	{
//		cout << "Animal虚析构函数调用" << endl;
//	}*/
//	//利用虚析构可以解决 父类指针释放子类对象时不干净的问题
//	virtual ~Animal() = 0;
//	//纯虚析构 需要声明也需要实现
//	//有了纯虚析构之后 这个类也属于抽象类 无法实例化对象
//	//纯虚函数
//	virtual void speak() = 0;
//};
//Animal::~Animal() 
//{
//	cout << "Animal的纯虚析构函数调用" << endl;
//};
//class Cat :public Animal 
//{
//public:
//	Cat(string name) 
//	{
//		cout << "Cat构造函数调用" << endl;
//		m_Name = new string(name);
//	}
//	virtual void speak() 
//	{
//		cout << *m_Name<<"小猫在说话" << endl;
//
//	}
//	string* m_Name;
//	~Cat() 
//	{
//		if (m_Name != NULL) 
//		{
//			cout << "Cat析构函数调用" << endl;
//			delete m_Name;
//			m_Name = NULL;
//			
//		}
//	}
//};
//void test01()
//{
//	Animal* animal = new Cat("Tom");
//	animal->speak();
//	//父类指针在析构时不会调用子类中析构函数：
//	//导致子类如果有堆区的数据，会出现内存的泄露情况
//	delete animal;
//}
//int main()
//{
//	test01();
//	system("pause");
//
//	return 0;
//}