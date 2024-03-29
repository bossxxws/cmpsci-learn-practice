//#include <iostream>
//using namespace std;
//#include<vector>
//
//class Solution 
//{
//public:
//	
//	vector<int> twoSum(vector<int>& numbers, int target)
//	{
//		
//		//创建数组储存答案
//		vector<int>v;
//		//计数器
//		int pi = 0;
//		int pj = numbers.size() - 1;
//		int n = numbers.size();
//		int t = 0;
//		for (t; t < n; t++) 
//		{
//			int k = numbers[pi] + numbers[pj];
//			if (k == target) 
//			{
//				v.push_back(pi + 1);
//				v.push_back(pj + 1);
//				return v;
//			}
//			else if (k < target) 
//			{
//				pi++;
//			}
//			else 
//			{
//				pj--;
//			}
//		}
//		return v;
//		
//	}
//		
//};
//int main()
//{
//	vector<int>v = { 5,25,75 };
//	int target = 100;
//	Solution s;
//	vector<int>t = s.twoSum(v, target);
//	cout << t[0] << endl;
//	cout << t[1] << endl;
//	cout << t.size() << endl;
//	system("pause");
//
//	return 0;
//}