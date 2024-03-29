#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        stack<int>tem;
        int s = temperatures.size();
        vector<int>res(s,0);//initialize the res's size as s
        for (int i=0;i<s;i++) 
        {
            while (!tem.empty() && temperatures[i] > temperatures[tem.top()]) 
            {
                int pdex = tem.top();
                tem.pop();
                res[pdex] = i - pdex;
            }
            tem.push(i);
        }
        return res;
    }
};
int main() 
{
	return 0;
}