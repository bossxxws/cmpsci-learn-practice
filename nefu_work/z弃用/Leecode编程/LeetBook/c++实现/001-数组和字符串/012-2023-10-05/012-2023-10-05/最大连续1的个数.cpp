//#include <iostream>
//using namespace std;
//#include<vector>
//
//class Solution {
//public:
//	int findMaxConsecutiveOnes(vector<int>& nums)
//	{
//		int l = 0, f = 0;
//		int n = nums.size();
//		int max = 0;
//		while (f < n) 
//		{
//			int count = 0;
//			while (f < n &&nums[f] != 1)
//			{
//				f++;
//			}
//			while (f < n && nums[f] == 1)
//			{
//				l++;
//				f++;
//				count++;
//			}
//			if (count > max) 
//			{
//				max = count;
//			}
//			
//		}
//		return max;
//	}
//};
//
//int main()
//{
//	vector<int>nums = { 1, 1, 0, 1, 1, 1,1,1,1,1,0,0 };
//	Solution s;
//	int k = s.findMaxConsecutiveOnes(nums);
//	cout << k << endl;
//
//	system("pause");
//
//	return 0;
//}
// --------------------------------------------------------------------------------------------------

//class Solution {
//public:
//	int findMaxConsecutiveOnes(vector<int>& nums) {
//		int maxvalue = 0;
//		int count = 0;
//		for (const auto& item : nums) {      // 弄懂这一行item是怎么回事
//			if (item == 1) {
//				count++;
//				if (maxvalue < count) {
//					maxvalue = count;
//				}
//			}
//			else {
//				count = 0;
//			}
//		}
//		return maxvalue;
//	}
//};