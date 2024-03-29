//#include <iostream>
//using namespace std;
//#include<vector>
////vector容器存放自定义数据类型
//class Person 
//{
//public:
//	Person(string name, int age) 
//	{
//		this->m_Name = name;
//		this->m_Age = age;
//	}
//	string m_Name;
//	int m_Age;
//
//};
//void test01() 
//{
//	vector<Person>v;
//	Person p1("aaa", 10);
//	Person p2("bbb", 10);
//	Person p3("ccc", 10);
//	Person p4("ddd", 10);
//	Person p5("eee", 10);
//	//向容器中添加数据
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	v.push_back(p4);
//	v.push_back(p5);
//
//	//遍历容器中的数据
//	//it为person实例的指针，解引用得person，然后.出来数据
//	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) 
//	{
//		cout << "姓名 " << (*it).m_Name << " 年龄 " << (*it).m_Age << endl;
//	}
//
//}
////存放自定义数据类型 指针
//void test02() 
//{
//	vector<Person*>v;
//	Person p1("aaa", 10);
//	Person p2("bbb", 10);
//	Person p3("ccc", 10);
//	Person p4("ddd", 10);
//	Person p5("eee", 10);
//	//向容器中添加数据     
//	v.push_back(&p1);
//	v.push_back(&p2);
//	v.push_back(&p3);
//	v.push_back(&p4);
//	v.push_back(&p5);
//
//	//遍历容器中的数据
//	//it 一个Person实例地址的指针，指向存放Person实例地址的地址
//	//*it 解引用得Person实例得地址
//	//通过地址，箭头来访问数据
//	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << "姓名 " << (*it)->m_Name << " 年龄 " << (*it)->m_Age << endl;
//	}
//
//}
//int main()
//{
//	test01();
//	test02();
//	system("pause");
//
//	return 0;
//}