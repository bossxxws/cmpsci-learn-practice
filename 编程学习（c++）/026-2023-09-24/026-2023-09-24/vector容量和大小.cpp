//#include <iostream>
//using namespace std;
//#include<vector>
//
//void printvector(vector<int>v) 
//{
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) 
//	{
//		cout <<  * it << " ";
//	}
//	cout << endl;
//}
//
//void test01() 
//{
//	vector<int>v1;
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//	}
//	
//	printvector(v1);
//	if (v1.empty()) 
//	{
//		cout << "v1 为空" << endl;
//	}
//	else 
//	{
//		cout << "不为空" << endl;
//		cout << "v1的容量为" << v1.capacity() << endl;
//		cout << "v1的大小为" << v1.size() << endl;
//	}
//	//重新指定大小 本来容量是10
//	v1.resize(15);
//	printvector(v1);//多打印出了五个0  默认空位置是0（书上说过）
//	//也可以用其他数填充
//	v1.resize(16, 100);
//	printvector(v1);//由于之前已经填充过了，只有新的第十六个空位填充的是100
//	v1.resize(5);
//	printvector(v1);//如果指定之后短了，会删除
//}
//
//int main()
//{
//	test01();
//	system("pause");
//
//	return 0;
//}