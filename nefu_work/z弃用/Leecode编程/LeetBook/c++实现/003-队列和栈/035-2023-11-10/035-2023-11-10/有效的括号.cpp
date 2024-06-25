#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<unordered_map>
#include<stack>
class Solution {
public:
    bool isValid(string s) 
    {
        stack<char>q;
        while (s.length())
        {
            if (s[0] == '{')
            {
                q.push('}');
                s.erase(0, 1);
            }
            else if (s[0] == '(')
            {
                q.push(')');
                s.erase(0,1);
            }
            else if (s[0] == '[')
            {
                q.push(']');
                s.erase(0, 1);
            }
            else if (s[0] == '}' || s[0] == ')'||s[0]==']')
            {
                if (q.empty())
                {
                    return false;
                }
                else if(s[0]==q.top())
                {
                    q.pop();
                    s.erase(0, 1);
                }
                else 
                {
                    return false;
                }
            }
            else
            {
                s.erase(0, 1);
            }
        }
        if (q.empty())
        {
            return true;
        }
        else return false;

    }
};
Solution s;
int main() 
{
    bool k = s.isValid("()");
    cout << k << endl;
	return 0;
}