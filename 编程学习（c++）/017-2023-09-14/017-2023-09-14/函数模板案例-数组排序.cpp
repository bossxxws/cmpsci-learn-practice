#include <iostream>
using namespace std;
//实现通用 对数组进行排序的函数
//规则 从大到小
//算法 选择
//测试 char数组 int数组
//排序算法
//实现交换函数模板
template<class T>
void mySwap(T&a,T&b)
{
	T temp = a;
	a = b;
	b = temp;

}

template<class T>
void mySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;//认定最大值下标
		for (int j = i + 1; j < len; j++)
		{
			//认定的最大值比遍历的数值要小，说明j下标的元素才是真正的最大值
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		if (max != i)
		{
			//交换max和i元素
			mySwap(arr[max], arr[i]);
		}
	}
}


//提供打印数组模板
template<class T>
void printArray(T arr[], int len) 
{
	for (int i = 0; i < len; i++) 
	{
		cout << arr[i] << " ";
	}
}
void test01() 
{
	char charArr[] = "badcfe";
	int num = sizeof(charArr) / sizeof(charArr[0]);
	mySort(charArr, num);
	printArray(charArr, num);
}
int main()
{
	test01();
	system("pause");

	return 0;
}