#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution 
{
public:
	int minSubArrayLen(int target, vector<int>& nums) 
	{
		int f = 0, l = 0, ans = nums.size();
		int sum = 0;
		int n = nums.size();
		for (f; f < n; f++) 
		{
			sum = sum + nums[f];
			if (sum >=target) 
			{
				while (sum - nums[l] >= target)
				{
					sum = sum - nums[l];
					l++;
				}
				if (f - l + 1 < ans)
				{
					ans = f - l + 1;
				}
			}
		}
		if (sum >=target) 
		{
			return ans;
		}
		else 
		{
			return 0;
		}
	}
};

int main()
{
	int target = 5;
	vector<int>nums = { 2, 3, 1, 1, 1 };
	Solution s;
	int k = s.minSubArrayLen(target, nums);
	cout << k << endl;
	system("pause");

	return 0;
}