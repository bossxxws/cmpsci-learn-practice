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
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) 
    {
        int n = s.size();
        int l = 0, r = 0;
        int mid = -1;
        int ans = 0;
        while (r < n) 
        {
            char c1 = s[l];
            while (r < n && s[r] == c1) r++;
            if (r == n) 
            {
                ans = max(ans, r - l);
                break;
            }
            mid = r;
            char c2 = s[r];
            while (r < n && (s[r] == c1 || s[r] == c2)) r++;
            ans = max(ans, r - l);
            l = mid;
            r = mid;
        }
        return ans;
    }
};

int main() 
{
	return 0;
}