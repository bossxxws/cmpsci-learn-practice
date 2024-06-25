#include <iostream>
using namespace std;
#include<vector>
#include <algorithm>

class Solution 
{
public:
	vector<int>a1;
	int arrayPairSum(vector<int>& nums)
	{
		int m = nums.size();
		//冒泡排序超时
		/*for (int i = 0; i < m - 1; i++)
		{
			for (int j = 0; j < m-1 - i; j++)
			{
				if (nums[j] > nums[j + 1])
				{

					int temp = nums[j];
					nums[j] = nums[j + 1];
					nums[j + 1] = temp;
				}
			}
		}*/
		//直接用方法
		sort(nums.begin(), nums.end());//algorithm中的方法
		int sum = 0;
		for (int k = 0; k < m; k++) 
		{
			if (k % 2 == 0) 
			{
				sum = sum + nums[k];
				a1.push_back(nums[k]);
			}
		}
		return sum;
	}
};


int main()
{
	vector<int>k = { 1, 4, 3, 2 };
	Solution s;
	int va = s.arrayPairSum(k);

	cout << va << endl;
	cout << 7000/400*7 << endl;

	system("pause");

	return 0;
}