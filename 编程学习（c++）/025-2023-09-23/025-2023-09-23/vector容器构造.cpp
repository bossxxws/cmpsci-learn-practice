//#include <iostream>
//using namespace std;
//#include<vector>
//
////�ṩ����ӿ�
//void printvector(vector<int>v) 
//{
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) 
//	{
//		cout << " "<< * it;
//	}
//	cout << endl;
//}
//
////vector��������
//
//void test01() 
//{
//	vector<int>v1;//Ĭ�Ϲ��� �޲ι���
//	for (int i = 0; i < 10; i++) 
//	{
//		v1.push_back(i);
//	}
//	printvector(v1);
//
//	//ͨ�����䷽ʽ���й���
//	vector<int>v2(v1.begin(), v1.end());
//	printvector(v2);
//
//	//n��elem����
//	vector<int>v4(10, 114514);// ʮ�� 114514
//	printvector(v4);
//
//	//��������
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