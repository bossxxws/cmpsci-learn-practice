#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
#include<unordered_set>
class Solution
{
public:
    unordered_set<int> s;
    bool isHappy(int n) 
    {
        int res = getres(n);
        while (s.find(res) == s.end()) 
        {
            s.insert(res);
            res = getres(res);
        }
        return res == 1;
    }
    int getres(int s)
    {
        int res = 0;
        while (s > 0)
        {
            int n = s % 10;
            s = s / 10;
            res = res + n * n;
        }
        return res;
    }
};

int main() 
{
    Solution s;
    bool k=s.isHappy(19);
    cout << k << endl;
	return 0;
}