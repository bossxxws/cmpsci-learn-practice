#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<iostream>
#include<queue>
using namespace std;

class Solution 
{
public:
    struct s
    {
        int newroot;//each levels' root
        int step;//level
    }s1, s2;//initialize two structs
    int numSquares(int n)
    {
        queue<s>q;//initialize a queue contain
        s1.newroot = n; 
        s1.step = 0;//initialize the initial level is 0
        q.push(s1);//out s1 in container
        while (!q.empty())
        {
            s1 = q.front();
            q.pop();//handle the earliest element 
            s1.step++;
            for (int i = 1; i * i <= s1.newroot; i++)
            {
                s2.newroot = s1.newroot - i * i;
                s2.step = s1.step;
                q.push(s2);
                if (s2.newroot == 0)
                {

                    return s2.step;
                }
            }
        }
        return 0;
    }
};
Solution s;
int main() 
{
    int k=s.numSquares(97);
    cout << k << endl;
	return 0;
}