#include <iostream>
using namespace std;
struct Person {
	std::string name;
	int age;
};



int main()
{
	Person* p = new Person();  // ����һ��ָ�� Person �����ָ��

	p->name = "John";    // ʹ�� p-> ������ָ����ָ�����ĳ�Ա
	p->age = 30;

	//std::cout << *p << std::endl;  // �����޷�ֱ�����ָ�����
	std::cout << p->name << std::endl;  // ��������Ա��ֵ john
	std::cout << (*p).name << std::endl;  // ��Ч����һ�У�ʹ�����źͽ����ò����� john
	std::cout << p->age << std::endl;//30
	std::cout << (*p).age << std::endl;//30
	//�Ҷ��߶������޸Ķ����ֵ

	system("pause");

	return 0;
}