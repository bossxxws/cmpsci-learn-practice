#include <iostream>
using namespace std;
#include<vector>
class Solution 
{
public:
	void moveZeroes(vector<int>& nums)
	{
		int n = nums.size();
		int f = 0, s = 0;
		while (f < n)
		{
			while ( f < n && nums[f] == 0 )
			{
				f++;
			}
			while (f < n&&nums[f] != 0 )
			{
				swap(nums[f++], nums[s++]);
			}
		}
		
		
		
	}
};



int main()
{
	vector<int> nums = { 0,0 };
	Solution S;
	S.moveZeroes(nums);
	cout << nums[1] << endl;
	system("pause");

	return 0;
}