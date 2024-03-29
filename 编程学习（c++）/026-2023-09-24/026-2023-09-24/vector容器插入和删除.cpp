//#include <iostream>
//using namespace std;
//#include<vector>
//
//void printvector(vector<int>v) 
//{
//	//通过冒号拿到一个迭代器
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) 
//	{
//		cout <<  * it << " ";
//	}
//	cout << endl;
//}
//
//
//void test01() 
//{
//	//尾插
//	vector<int>v1;
//	v1.push_back(10);
//	v1.push_back(20);
//	v1.push_back(30);
//	v1.push_back(40);
//	v1.push_back(50);
//	v1.push_back(60);
//	v1.push_back(70);
//
//	//遍历
//	printvector(v1);
//
//	//尾删
//	v1.pop_back();
//	printvector(v1);
//	
//	//插入
//	v1.insert(v1.begin(), 100);//第一个参数是迭代器
//	printvector(v1);
//
//	v1.insert(v1.begin(), 2, 1000);//插入n个element，在指定的位置上
//	printvector(v1);        
//
//	//删除
//	v1.erase(v1.begin());//参数也是迭代器
//	printvector(v1);
//
//	v1.erase(v1.begin(), v1.end());//等价于v1.clear()
//	printvector(v1);
//
//
//
//}
//int main()
//{
//	test01();
//
//	system("pause");
//
//	return 0;
//}