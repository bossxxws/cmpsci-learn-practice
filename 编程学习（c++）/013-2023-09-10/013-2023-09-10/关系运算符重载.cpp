#include <iostream>
using namespace std;
//��ϵ������������õ�����������֪����ô�ȶԵ�
//�Զ��������������û�а취�ȶԵģ�����Ҫ����
class Person 
{
public:
	Person(string name, int age) 
	{
		m_Name = name;
		m_Age = age;
		
	}
	//���ع�ϵ�����==��
	bool operator==(Person& p)//д��Person����������ΪҪ��Person����бȽϲ���
	//���ز�����������Ϊ��ϵ������Ľ��ͨ����һ������ֵ����ʾ���滹�Ǽ�
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
		cout << "p1 �� p2 ����ȵ�" << endl;

	}
	else 
	{
		cout << "p1 �� p2 �ǲ���ȵ�" << endl;
	}
}
int main()
{
	test01();

	system("pause");

	return 0;
}