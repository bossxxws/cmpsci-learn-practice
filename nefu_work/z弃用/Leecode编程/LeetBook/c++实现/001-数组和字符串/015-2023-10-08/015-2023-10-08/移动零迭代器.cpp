#include <iostream>
using namespace std;
#include<vector>

class Solution {
public:
	void moveZeroes(vector<int>& nums) 
	{
		int n = nums.size();
		for (vector<int>::iterator it = nums.begin();it != nums.end();) 
		{
			if (*it == 0) 
			{
				nums.erase(it);
				nums.push_back(0);
			}
			else 
			{
				it++;
			}
		}
	}
};
//³¬Ê±£¡

int main()
{

	system("pause");

	return 0;
}