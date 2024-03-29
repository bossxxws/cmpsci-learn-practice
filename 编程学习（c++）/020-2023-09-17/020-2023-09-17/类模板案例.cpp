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
		//����β�巨�������в�������
		arr1.Push_Back(i);
	}
	cout << "arr1�еĴ�ӡ���Ϊ" << endl;
	printIntarray(arr1);
	cout << arr1.getCapacity() << " arr1������ " << endl;
	cout << arr1.getSize() << " arr1�Ĵ�С " << endl;

	MyArray<int>arr2(arr1);
	cout << "arr2�Ĵ�ӡ " << endl;
	printIntarray(arr2);
	arr2.Pop_Back();
	
	cout << "arr2βɾ��" << endl;
	cout << arr2.getCapacity()<< endl;
	cout << arr2.getSize() << endl;
}

//�����Զ�����������
class Person 
{
public:
	Person() {};//Ĭ�Ϲ����ʵ��
	Person(string name, int age) //�вι���
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;

};

void printPersonArray(MyArray<Person>& arr) //ΪʲôҪ�����ã�
{
	for (int i = 0; i < arr.getSize(); i++) 
	{
		cout << "���� " << arr[i].m_Name << " ���� " << arr[i].m_Age << endl;

	}

}

void test02() 
{

	MyArray<Person>arr(10);
	Person p1("�����", 999);
	Person p2("��С��", -2000);
	Person p3("����", 35); 
	Person p4("��������", 37);
	arr.Push_Back(p1);
	arr.Push_Back(p4);
	
	//��ӡ
	printPersonArray(arr);

	//��ӡ�����ʹ�С
	cout << "��ǰ����ռ�ã�" << arr.getSize() << " / " << arr.getCapacity() << endl;
}
int main()
{
	//test01();
	test02();
	system("pause");

	return 0;
}