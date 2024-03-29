#include <iostream>
using namespace std;
//1.构造函数 进行初始化
class Person 
{
public:
	Person() 
	{
		cout << "Person构造函数的调用" << endl;
	}
	~Person() 
	{
		cout << "析构函数的调用" << endl;//销毁时调用
	}
};
void test01()
{
	Person p;//这个会销毁
}

int main()
{
	test01();//调用（构造）-销毁（析构）
	Person p1;
	Person p2;
	Person p3;//这三个在main结束前不会销毁
	system("pause");

	return 0;
}