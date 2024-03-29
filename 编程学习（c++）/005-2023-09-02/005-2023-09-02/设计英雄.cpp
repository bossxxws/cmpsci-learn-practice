#include <iostream>
using namespace std;
#include<string>
//1.创建英雄结构体
struct 英雄
{
	string name;
	int age;
	string sex;
};
英雄 arry[5];
//3.把数组按年龄升序排列(冒泡排序)
void bubble_sort(英雄 arry[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arry[j + 1].age < arry[j].age)
			{
				int temp = arry[j + 1].age;
				arry[j + 1].age = arry[j].age;
				arry[j].age = temp;
			}
		}
	}
}

int main()
{
	英雄 arry[5] =
	{
		{"刘宇澄",78,"男"},
		{"刀哥",36,"男"},
		{"虎哥",37,"男"},
		{"GG-bond",12,"活猪"},
		{"熊大",8,"熊"}
	};
	int len = sizeof(arry) / sizeof(arry[0]);
	bubble_sort(arry, len);
	for (int i = 0; i < len; i++)
	{
		cout << "英雄名称:  " << arry[i].name << "  英雄性别:  " << arry[i].sex << "  英雄年龄:  " << arry[i].age << endl;
	}
	//4.打印结果
	system("pause");

	return 0;
}