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
//		cout << "v1 Ϊ��" << endl;
//	}
//	else 
//	{
//		cout << "��Ϊ��" << endl;
//		cout << "v1������Ϊ" << v1.capacity() << endl;
//		cout << "v1�Ĵ�СΪ" << v1.size() << endl;
//	}
//	//����ָ����С ����������10
//	v1.resize(15);
//	printvector(v1);//���ӡ�������0  Ĭ�Ͽ�λ����0������˵����
//	//Ҳ���������������
//	v1.resize(16, 100);
//	printvector(v1);//����֮ǰ�Ѿ������ˣ�ֻ���µĵ�ʮ������λ������100
//	v1.resize(5);
//	printvector(v1);//���ָ��֮����ˣ���ɾ��
//}
//
//int main()
//{
//	test01();
//	system("pause");
//
//	return 0;
//}