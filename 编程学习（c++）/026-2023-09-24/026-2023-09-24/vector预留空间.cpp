#include <iostream>
using namespace std;
#include<vector>

//vector容器 预留空间

void test01()
{
	int num = 0;
	int* p = NULL;
	vector<int>v1;

	//利用reserve预留空间
	v1.reserve(10000);//有了预留10000就只用开辟一次空间
	for (int i = 0; i < 10000; i++)
	{
		v1.push_back(i);

		if (p != &v1[0]) //开辟内存后首地址发生变化，因为找到更大的空间，原来的空间作废
		{
			p = &v1[0];
			num++;
		}
	}
	cout << num << endl;
}

int main()
{
	test01();

	system("pause");

	return 0;
}