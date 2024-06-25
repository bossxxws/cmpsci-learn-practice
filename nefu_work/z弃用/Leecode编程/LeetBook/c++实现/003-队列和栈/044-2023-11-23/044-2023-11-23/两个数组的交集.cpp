#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
#include<unordered_set>
class Solution
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_set<int>s1, s2;
        vector<int>res;
        while (!nums1.empty()) 
        {
            s1.emplace(nums1[0]);
            nums1.erase(nums1.begin());
        }//put all elements in nums1 in set
        int k = nums2.size();
        for (int i = 0; i < k; i++) 
        {
            if (s1.find(nums2[i]) == s1.end())
            {
                continue;
            }
            else 
            {
                s2.emplace(nums2[i]);
            }
        }
        for (auto it=s2.begin();it!=s2.end();it++) 
        {
            res.push_back(*it);
        }
        return res;
    }
};
int main() 
{
	return 0;
}