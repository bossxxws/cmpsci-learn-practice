#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
class Solution
{
public:
    string decodeString(string s) 
    {
        stack<string>aim;
        stack<int>times;
        //temple nums
        int nums = 0;
        //temple strings
        string tem = "";
        for (int i = 0; i < s.size(); i++) 
        {
            if (s[i]>='0' &&s[i]<='9')
            {
                nums = nums * 10 + (s[i] - '0');
            }
            else if (s[i]>='a' &&s[i]<='z')
            {
                tem = tem + s[i];
            }
            else if (s[i] == '[') 
            {
                times.push(nums);
                nums = 0;
                aim.push(tem);
                tem = "";
            }
            else if (s[i] == ']') 
            {
                int number = times.top();
                times.pop();
                string t = tem;
                for (int j = 0; j < number - 1; j++) 
                {
                    tem = t + tem;
                }
                string newstr = aim.top();
                aim.pop();
                tem = newstr + tem;
            }
        }
        return tem;
    }
};
int main() 
{
    Solution s;
    string s1 = "100[leet]";
    string res=s.decodeString(s1);
    cout << res << endl;

	return 0;
}