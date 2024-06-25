//#include <iostream>
//using namespace std;
//#include<vector>
//
//class Solution {
//public:
//	int removeElement(vector<int>& nums, int val) 
//	{
//		int fast = 0;
//		int slow = 0;
//		int n = nums.size();
//		while (fast < n) 
//		{
//			while (fast <n&&nums[fast] == val) 
//			{
//				fast++;
//			}
//			
//			while (fast < n && nums[fast] != val)
//			{
//				nums[slow] = nums[fast];
//				slow++;
//				fast++;
//			}
//		}		
//		return slow;
//	}
//};
//
//int main()
//{
//	vector<int> nums =  {3,2,2,2,2,2,2,2,2,3};
//	Solution s;
//	int k = s.removeElement(nums, 2); 
//	cout << k << endl;
//	system("pause");
//
//	return 0;
//}