#include <iostream>
using namespace std;
#include<vector>
class Solution 
{
public:
	int findMin(vector<int>& nums) 
	{
		int temp = nums[0];
		int n = nums.size();
		for (int i = 1; i < n; i++) 
		{
			if (nums[i] < temp) 
			{
				temp = nums[i];
			}
		}
		return temp;

	}
};

int main()
{

	system("pause");

	return 0;
}