#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
class Solution 
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		unordered_map<int, int>hashtable;
		for (int i = 0; i < nums.size(); i++) 
		{
			auto it = hashtable.find(target - nums[i]);
			if (it != hashtable.end()) 
			{
				return { it->second,i };
			}
			hashtable[nums[i]]=i;
		}
		return {};
	}
};
int main() 
{
	int att[][1] = 
	{
		{1},
		{2},
		{3}
	};
	cout << att[0][2] << endl;
	return 0;
}