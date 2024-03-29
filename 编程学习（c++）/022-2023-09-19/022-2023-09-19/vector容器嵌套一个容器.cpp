//#include <iostream>
//using namespace std;
//#include<vector>;
//
////容器嵌套容器
//void test01()
//{
//	vector<vector<int>>v;
//
//	//创建小容器
//	vector<int>v1;
//	vector<int>v2;
//	vector<int>v3;
//	vector<int>v4;
//	//向小容器中添加数据
//	for (int i = 0; i < 4; i++) 
//	{
//		v1.push_back(i + 1);
//		v2.push_back(i + 2);
//		v3.push_back(i + 3);
//		v4.push_back(i + 4);
//
//	}
//
//	//将小容器插入到大的容器中
//	v.push_back(v1);
//	v.push_back(v2);
//	v.push_back(v3);
//	v.push_back(v4);
//
//	//通过大容器，把所有数据遍历
//	
//	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) 
//	{
//		
//		//(*it)     //*it 是尖括号里的东西 ------ 一个容器
//		//尖括号里是什么数据类型，解出来就是什么数据类型
//		//而 it 是容器的指针，指向容器的地址
//		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++) 
//		{
//			cout << *vit << " ";
//			
//		}
//
//
//		cout << endl;
//
//	}
//}
//
//int main()
//{
//	test01();
//	system("pause");
//
//	return 0;
//}