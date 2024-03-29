#include <iostream>
using namespace std;
#include<vector>

class Solution 
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		
		for (vector<int>::iterator it = nums.begin();it != nums.end()-1;)
		{
			while (it + 1 < nums.end()  && *it == *(it + 1)  )
			{
				nums.erase(it + 1);
			}
			if (it < nums.end()-1) 
			{
				it++;
			}
		}
		return nums.size();
	}
};

int main()
{
	Solution s;
	vector<int> nums = { 1,1 };
	int k = s.removeDuplicates(nums);
	cout << k << endl;
	system("pause");

	return 0;
}