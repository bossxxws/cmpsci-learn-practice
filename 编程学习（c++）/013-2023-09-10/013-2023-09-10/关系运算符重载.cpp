#include <iostream>
using namespace std;
//关系运算符对于内置的数据类型是知道怎么比对的
//自定义的数据类型是没有办法比对的，所以要重载
class Person 
{
public:
	Person(string name, int age) 
	{
		m_Name = name;
		m_Age = age;
		
	}
	//重载关系运算符==号
	bool operator==(Person& p)//写在Person类里面是因为要对Person类进行比较操作
	//返回布尔类型是因为关系运算符的结果通常是一个布尔值，表示是真还是假
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age) 
		{
			
			return true;

		}
		return false;
	}
	string m_Name;
	int m_Age;
};


void test01() 
{
	Person p1("Tom", 17);
	Person p2("Tom", 18);
	if (p1 == p2) 
	{
		cout << "p1 和 p2 是相等的" << endl;

	}
	else 
	{
		cout << "p1 和 p2 是不相等的" << endl;
	}
}
int main()
{
	test01();

	system("pause");

	return 0;
}