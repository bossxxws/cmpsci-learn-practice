#include <iostream>
using namespace std;
//#include<vector>
//
////vector容器-互换容器
//void pv(vector<int>v) 
//{
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) 
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
////1、基本的使用
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
//	//交换
//	cout << "交换后" << endl;
//	swap(v1, v2);
//	pv(v1);
//	pv(v2);
//	
//}
//
////2、实际的用途
////巧用swap可以收缩内存空间
//void test02() 
//{
//	vector<int>v3;
//	for (int i = 0; i < 10000; i++) 
//	{
//		v3.push_back(i);
//	}
//	cout << "V的容量大小" << v3.capacity() << endl;
//	cout << "V的大小为" << v3.size() << endl;
//
//	v3.resize(3);//重新指定大小
//	cout << "V的容量大小" << v3.capacity() << endl;
//	cout << "V的大小为" << v3.size() << endl; //很大的容量只用了很小的空间，浪费
//
//	//巧用swap收缩内存
//	vector<int>(v3).swap(v3);
//	cout << "V的容量大小" << v3.capacity() << endl;
//	cout << "V的大小为" << v3.size() << endl;
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