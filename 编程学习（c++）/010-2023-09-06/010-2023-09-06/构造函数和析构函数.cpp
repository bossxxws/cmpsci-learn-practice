#include <iostream>
using namespace std;
//1.���캯�� ���г�ʼ��
class Person 
{
public:
	Person() 
	{
		cout << "Person���캯���ĵ���" << endl;
	}
	~Person() 
	{
		cout << "���������ĵ���" << endl;//����ʱ����
	}
};
void test01()
{
	Person p;//���������
}

int main()
{
	test01();//���ã����죩-���٣�������
	Person p1;
	Person p2;
	Person p3;//��������main����ǰ��������
	system("pause");

	return 0;
}