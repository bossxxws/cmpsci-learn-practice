#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
#include<unordered_set>
#include<unordered_map>
class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        unordered_map<int, size_t>aim;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            aim[nums[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (aim[nums[i]] != 2)
            {
                return nums[i];
            }
        }
        return 0;
    }
};
int main() 
{
	return 0;
}