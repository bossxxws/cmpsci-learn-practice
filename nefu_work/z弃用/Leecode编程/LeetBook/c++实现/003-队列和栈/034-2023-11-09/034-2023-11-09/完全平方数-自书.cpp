#include<iostream>
using namespace std;
#include<vector>
#include<queue>
class Solution 
{
public:
    struct s
    {
        int level;
        int root;
    } s1, s2;
    int numSquares(int n)
    {
        s1.level = 0;
        s1.root = n;
        queue<s>q;
        q.push(s1);
        while (!q.empty()) 
        {
            s1 = q.front();
            q.pop();
            for (int i = 1; i * i <= s1.root; i++) 
            {
                s2.level = s1.level;
                s2.root = s1.root - i * i;
                s2.level++;
                q.push(s2);
                if (s2.root == 0) 
                {
                    return s2.level;
                }
            }
        }
        return false;
    }
};
Solution s;
int main()
{
    int k = s.numSquares(97);
    cout << k << endl;
    return 0;
}