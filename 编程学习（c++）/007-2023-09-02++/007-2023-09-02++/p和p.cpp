#include <iostream>
using namespace std;
struct Person {
	std::string name;
	int age;
};



int main()
{
	Person* p = new Person();  // 创建一个指向 Person 对象的指针

	p->name = "John";    // 使用 p-> 来访问指针所指向对象的成员
	p->age = 30;

	//std::cout << *p << std::endl;  // 错误，无法直接输出指针对象
	std::cout << p->name << std::endl;  // 输出对象成员的值 john
	std::cout << (*p).name << std::endl;  // 等效于上一行，使用括号和解引用操作符 john
	std::cout << p->age << std::endl;//30
	std::cout << (*p).age << std::endl;//30
	//且二者都可以修改对象的值

	system("pause");

	return 0;
}