#include <iostream>
using namespace std;
#include<vector>

//vector���� Ԥ���ռ�

void test01()
{
	int num = 0;
	int* p = NULL;
	vector<int>v1;

	//����reserveԤ���ռ�
	v1.reserve(10000);//����Ԥ��10000��ֻ�ÿ���һ�οռ�
	for (int i = 0; i < 10000; i++)
	{
		v1.push_back(i);

		if (p != &v1[0]) //�����ڴ���׵�ַ�����仯����Ϊ�ҵ�����Ŀռ䣬ԭ���Ŀռ�����
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