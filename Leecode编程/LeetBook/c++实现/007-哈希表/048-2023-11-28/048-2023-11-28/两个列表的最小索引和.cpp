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
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) 
    {
        vector<string>res;
        unordered_map<string,int>s1;
        int min = 9999;
        vector<int>minj;
        for (int i=0;i<list1.size();i++) 
        {
            s1[list1[i]]=i;
        }
        for (int j = 0; j < list2.size(); j++) 
        {
            if (s1.find(list2[j]) != s1.end()) 
            {
                int tem = j + s1[list2[j]];
                if (tem < min) 
                {
                    min = tem;
                } 
            }
        }
        for (int j = 0; j < list2.size(); j++)
        {
            if (s1.find(list2[j]) != s1.end())
            {
                int tem = j + s1[list2[j]];
                if (tem == min)
                {
                    minj.push_back(j);
                }
            } 
        }
        for(auto ele:minj)res.push_back(list2[ele]);
        return res;
    }
};
int main() 
{
	return 0;
}