#include <iostream>
using namespace std;
#include<vector>
class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		int fast = 0, slow = 0, n = 0;
		while (fast < nums.size())
		{
			while (fast < nums.size() && nums[fast] == nums[slow])
			{
				fast++;
			}
			while (fast < nums.size() && nums[fast] != nums[slow])
			{
				nums[++slow] = nums[fast++];
			}
		}
		return slow + 1;//返回的是数组长度
	}
};
int main()
{

	system("pause");

	return 0;
}