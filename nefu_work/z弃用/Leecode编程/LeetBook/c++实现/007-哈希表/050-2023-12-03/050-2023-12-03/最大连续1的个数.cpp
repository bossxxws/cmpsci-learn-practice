#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;
class Solution 
{
public:
    int longestOnes(vector<int>& nums, int k)
    {
        int ans;
        int n = nums.size();
        int l = 0, r = 0;
        int cou=0;
        while (r < n)
        {
            if (nums[r] == 1)cou++;
            r++;
            if (r - l  - cou > k)
            {
                if (nums[l] == 1)cou--;
                l++;
            }
        }
        return r - l;
    }
};
int main() 
{
    vector<int>s = { 1,1,1,0,0,0,1,1,1,1,0 };
    int k = 2;
    Solution f;
    int ans = f.longestOnes(s, k);
    cout << ans;
	return 0;
}