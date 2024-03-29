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
        vector<vector<string>> res;
        map<int, vector<string>>aux;
        unordered_set<int> keys;
        for (auto ele : strings)
        {
            keys.emplace(ele.size());
            aux[ele.size()].push_back(ele);
           
        }
        for (auto ele1 : keys)
        {
            sort(aux[ele1].begin(), aux[ele1].end());
            res.push_back(aux[ele1]);
        }
        return res;
    }
};
int main() 
{
    Solution s;
    vector<string> ex={"ab","ba"};
    vector<vector<string>> res = s.groupStrings(ex);
    cout << res.data() << endl;
	return 0;
}