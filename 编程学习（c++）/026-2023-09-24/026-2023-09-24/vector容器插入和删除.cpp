//#include <iostream>
//using namespace std;
//#include<vector>
//
//void printvector(vector<int>v) 
//{
//	//ͨ��ð���õ�һ��������
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
//	//β��
//	vector<int>v1;
//	v1.push_back(10);
//	v1.push_back(20);
//	v1.push_back(30);
//	v1.push_back(40);
//	v1.push_back(50);
//	v1.push_back(60);
//	v1.push_back(70);
//
//	//����
//	printvector(v1);
//
//	//βɾ
//	v1.pop_back();
//	printvector(v1);
//	
//	//����
//	v1.insert(v1.begin(), 100);//��һ�������ǵ�����
//	printvector(v1);
//
//	v1.insert(v1.begin(), 2, 1000);//����n��element����ָ����λ����
//	printvector(v1);        
//
//	//ɾ��
//	v1.erase(v1.begin());//����Ҳ�ǵ�����
//	printvector(v1);
//
//	v1.erase(v1.begin(), v1.end());//�ȼ���v1.clear()
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