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
    int characterReplacement(string s, int k)
    {
        vector<int>times(26);
        //sliding window's left and right boundary
        int l = 0, r = 0;
        int maxtn = 0;
        int n = s.size();
        //when the r get the end of string s,break
        while(r<=n-1)
        {
            times[s[r] - 'A']++;
            if (times[s[r] - 'A'] > maxtn)maxtn = times[s[r] - 'A'];
            r++;
            if (maxtn + k < r - l)
            {
                times[s[l] - 'A']--;
                l++;
            }
        }
        return r - l;


    }
};
int main() 
{
	return 0;
}