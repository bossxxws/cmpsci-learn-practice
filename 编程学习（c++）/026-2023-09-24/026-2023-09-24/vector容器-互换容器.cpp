#include <iostream>
using namespace std;
//#include<vector>
//
////vector����-��������
//void pv(vector<int>v) 
//{
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) 
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
////1��������ʹ��
//
//void test01()
//{
//	vector<int>v1;
//	for (int i = 0; i < 10; i++) 
//	{
//		v1.push_back(i);
//	}
//
//	pv(v1);
//	vector<int>v2;
//	for (int i = 10; i > 0; i--)
//	{
//		v2.push_back(i);
//	}
//
//	pv(v2);
//
//	//����
//	cout << "������" << endl;
//	swap(v1, v2);
//	pv(v1);
//	pv(v2);
//	
//}
//
////2��ʵ�ʵ���;
////����swap���������ڴ�ռ�
//void test02() 
//{
//	vector<int>v3;
//	for (int i = 0; i < 10000; i++) 
//	{
//		v3.push_back(i);
//	}
//	cout << "V��������С" << v3.capacity() << endl;
//	cout << "V�Ĵ�СΪ" << v3.size() << endl;
//
//	v3.resize(3);//����ָ����С
//	cout << "V��������С" << v3.capacity() << endl;
//	cout << "V�Ĵ�СΪ" << v3.size() << endl; //�ܴ������ֻ���˺�С�Ŀռ䣬�˷�
//
//	//����swap�����ڴ�
//	vector<int>(v3).swap(v3);
//	cout << "V��������С" << v3.capacity() << endl;
//	cout << "V�Ĵ�СΪ" << v3.size() << endl;
//
//}
//
//int main()
//{
//	test01();
//	test02();
//
//	system("pause");
//
//	return 0;
//}