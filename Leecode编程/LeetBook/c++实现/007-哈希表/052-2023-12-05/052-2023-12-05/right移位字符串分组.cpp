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
    vector<vector<string>> groupStrings(vector<string>& strings) 
    {
        unordered_map<string, vector<string>> mp;
        for (string& str : strings)
        {
            string key = str;
            int a = str[0] - 'a';
            for (int i = 0; i < key.size(); i++)
            {
                key[i] = (key[i] - a + 26) % 26;
            }
            mp[key].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it) 
        {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};
int main() 
{
	return 0;
}