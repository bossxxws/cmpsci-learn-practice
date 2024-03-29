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
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> my_map;
        for (int i = 0; i < s.length(); i++)
        {
            if (my_map.count(s[i]) > 0)
            {
                if (my_map[s[i]] != t[i])
                {
                    return false;
                }
            }
            my_map.insert(make_pair(s[i], t[i]));
        }

        unordered_map<char, char> my_map2;
        for (int i = 0; i < t.length(); i++)
        {
            if (my_map2.count(t[i]) > 0)
            {
                if (my_map2[t[i]] != s[i])
                {
                    return false;
                }
            }
            my_map2.insert(make_pair(t[i], s[i]));
        }
        return true;
    }
};
int main() 
{
	auto it = "hello";
	cout << it << endl;
	return 0;
}