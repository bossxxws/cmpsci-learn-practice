#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>//��׼�㷨ͷ�ļ�
//������vector----���Ϊһ������
//����  -- vector
//�㷨  -- for_each
//������-- vector<int>::iterator


void myPrint(int k) 
{
	cout << k << endl;
}

void test01()
{

	//������һ��vector����������
	vector<int> v;

	//�������в�������
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	//ͨ�����������������е�����
	vector<int>::iterator itBegin = v.begin(); //��ʼ��������ָ�������е�һ��Ԫ��
	vector<int>::iterator itEnd = v.end();//������������ָ���������Ԫ�ص���һ��λ��

	//��һ�ֱ�����ʽ
	while (itBegin != itEnd)//��Ϊ�գ�������⣩ ---���󣡣�  ������
	{
		cout << *itBegin << endl;
		itBegin++;//�ȵ��ӵ���end�غϵ�ʱ��ͽ���
	}

	//�ڶ��ֱ�����ʽ
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
	{
		cout << *it << endl;
	}
	//�����ֱ�����ʽ ����stl���ṩ�ı����㷨
	for_each(v.begin(), v.end(), myPrint);
	//�ص�����

}
int main()
{
	test01();

	system("pause");

	return 0;
}