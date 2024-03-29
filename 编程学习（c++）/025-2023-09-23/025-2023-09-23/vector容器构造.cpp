//#include <iostream>
//using namespace std;
//#include<vector>
//
////提供输出接口
//void printvector(vector<int>v) 
//{
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) 
//	{
//		cout << " "<< * it;
//	}
//	cout << endl;
//}
//
////vector容器构造
//
//void test01() 
//{
//	vector<int>v1;//默认构造 无参构造
//	for (int i = 0; i < 10; i++) 
//	{
//		v1.push_back(i);
//	}
//	printvector(v1);
//
//	//通过区间方式进行构造
//	vector<int>v2(v1.begin(), v1.end());
//	printvector(v2);
//
//	//n个elem构造
//	vector<int>v4(10, 114514);// 十个 114514
//	printvector(v4);
//
//	//拷贝构造
//	vector<int>v3(v1);
//	printvector(v3);
//}
//
//
//
//int main()
//{
//	test01();
//	system("pause");
//
//	return 0;
//}