#include <iostream>
using namespace std;
#include "MyArray.hpp"

void printIntarray(MyArray<int>& arr)
{
	for (int i = 0; i < arr.getSize(); i++) 
	{
		cout << arr[i] << endl;

	}


}

void test01() 
{
	MyArray<int>arr1(5);
	
	MyArray<int>arr3(100);
	arr3 = arr1;
	for (int i = 0; i < 5; i++) 
	{
		//利用尾插法向数组中插入数据
		arr1.Push_Back(i);
	}
	cout << "arr1中的打印输出为" << endl;
	printIntarray(arr1);
	cout << arr1.getCapacity() << " arr1的容量 " << endl;
	cout << arr1.getSize() << " arr1的大小 " << endl;

	MyArray<int>arr2(arr1);
	cout << "arr2的打印 " << endl;
	printIntarray(arr2);
	arr2.Pop_Back();
	
	cout << "arr2尾删后" << endl;
	cout << arr2.getCapacity()<< endl;
	cout << arr2.getSize() << endl;
}

//测试自定义数据类型
class Person 
{
public:
	Person() {};//默认构造空实现
	Person(string name, int age) //有参构造
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;

};

void printPersonArray(MyArray<Person>& arr) //为什么要用引用？
{
	for (int i = 0; i < arr.getSize(); i++) 
	{
		cout << "姓名 " << arr[i].m_Name << " 年龄 " << arr[i].m_Age << endl;

	}

}

void test02() 
{

	MyArray<Person>arr(10);
	Person p1("孙悟空", 999);
	Person p2("朱小青", -2000);
	Person p3("刀哥", 35); 
	Person p4("国服韩信", 37);
	arr.Push_Back(p1);
	arr.Push_Back(p4);
	
	//打印
	printPersonArray(arr);

	//打印容量和大小
	cout << "当前容量占用：" << arr.getSize() << " / " << arr.getCapacity() << endl;
}
int main()
{
	//test01();
	test02();
	system("pause");

	return 0;
}