#include <iostream>
using namespace std;
//ʵ��ͨ�� �������������ĺ���
//���� �Ӵ�С
//�㷨 ѡ��
//���� char���� int����
//�����㷨
//ʵ�ֽ�������ģ��
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
		int max = i;//�϶����ֵ�±�
		for (int j = i + 1; j < len; j++)
		{
			//�϶������ֵ�ȱ�������ֵҪС��˵��j�±��Ԫ�ز������������ֵ
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		if (max != i)
		{
			//����max��iԪ��
			mySwap(arr[max], arr[i]);
		}
	}
}


//�ṩ��ӡ����ģ��
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