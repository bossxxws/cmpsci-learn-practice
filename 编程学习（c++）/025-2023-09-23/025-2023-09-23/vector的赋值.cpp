//#include <iostream>
//using namespace std;
//#include<vector>
//
//void printvector(vector<int>v) 
//{
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) 
//	{	
//	cout << " "<< * it;
//	}
//	cout << endl;
//}
//
//
//void test01() 
//{
//	vector<int>v1;
//	for (int i = 0; i < 10; i++) 
//	{
//		v1.push_back(i);
//	}
//	printvector(v1);
//
//	//vector¸³Öµ operate=
//	vector<int>v2;
//	v2 = v1;
//	printvector(v2);
//
//	//assign¸³Öµ
//	vector<int>v3;
//	v3.assign(v1.begin(), v1.end());
//	printvector(v3);
//
//	//n¸öelement
//	vector<int>v4;
//	v4.assign(10, 100);
//	printvector(v4);
//}
//int main()
//{
//	test01();
//	system("pause");
//
//	return 0;
//}