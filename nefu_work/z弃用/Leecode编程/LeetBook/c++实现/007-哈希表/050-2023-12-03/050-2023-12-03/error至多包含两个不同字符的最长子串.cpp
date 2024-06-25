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
        int max1 = 0, max2 = 0;
        vector<int> tem(26);
        int l = 0, r = 0, n = s.size();
        while (r < n) 
        {
            tem[s[r] - 'a']++;
            if (tem[s[r] - 'a'] > max1) 
            {
                max2 = max1;
                max1 = tem[s[r] - 'a'];
            }
            else if (tem[s[r] - 'a'] > max2)
            {
                max2 = tem[s[r] - 'a'];
            }
            r++;
            if (r - l  > max1 + max2)
            {
                if (max1 == tem[s[l] - 'a'])
                {
                    max1--;
                }
                else if(max2 == tem[s[l] - 'a'])
                {
                    max2--;
                }
                tem[s[l] - 'a']--;
                l++;
            }
        }
        return r - l;
    }
};
int main() 
{
    cout << 'A'-0;
	return 0;
}