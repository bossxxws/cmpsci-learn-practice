#include <iostream>
using namespace std;
#include<string>
//1.����Ӣ�۽ṹ��
struct Ӣ��
{
	string name;
	int age;
	string sex;
};
Ӣ�� arry[5];
//3.�����鰴������������(ð������)
void bubble_sort(Ӣ�� arry[], int len)
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
	Ӣ�� arry[5] =
	{
		{"�����",78,"��"},
		{"����",36,"��"},
		{"����",37,"��"},
		{"GG-bond",12,"����"},
		{"�ܴ�",8,"��"}
	};
	int len = sizeof(arry) / sizeof(arry[0]);
	bubble_sort(arry, len);
	for (int i = 0; i < len; i++)
	{
		cout << "Ӣ������:  " << arry[i].name << "  Ӣ���Ա�:  " << arry[i].sex << "  Ӣ������:  " << arry[i].age << endl;
	}
	//4.��ӡ���
	system("pause");

	return 0;
}