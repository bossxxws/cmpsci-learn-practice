#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>//标准算法头文件
//如何理解vector----理解为一个数组
//容器  -- vector
//算法  -- for_each
//迭代器-- vector<int>::iterator


void myPrint(int k) 
{
	cout << k << endl;
}

void test01()
{

	//创建了一个vector容器，数组
	vector<int> v;

	//向容器中插入数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	//通过迭代器访问容器中的数字
	vector<int>::iterator itBegin = v.begin(); //起始迭代器，指向容器中第一个元素
	vector<int>::iterator itEnd = v.end();//结束迭代器，指向容器最后元素的下一个位置

	//第一种遍历方式
	while (itBegin != itEnd)//不为空（个人理解） ---错误！！  见下面
	{
		cout << *itBegin << endl;
		itBegin++;//等到加到和end重合的时候就结束
	}

	//第二种遍历方式
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
	{
		cout << *it << endl;
	}
	//第三种遍历方式 利用stl中提供的遍历算法
	for_each(v.begin(), v.end(), myPrint);
	//回调函数

}
int main()
{
	test01();

	system("pause");

	return 0;
}