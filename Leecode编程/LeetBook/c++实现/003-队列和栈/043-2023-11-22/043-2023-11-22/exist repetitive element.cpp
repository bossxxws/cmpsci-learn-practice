#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
#include<unordered_set>
//version2
class Solution {
	public:
	    bool containsDuplicate(vector<int>& nums)
	    {
	        
	        unordered_set<int>aim;
	        while(!nums.empty())
	        {
	            if (aim.find(nums.back()) == aim.end()) 
	            {
	                aim.insert(nums.back());
					nums.pop_back();
	            }
	            else 
	            {
	                return true;
	            }
	        }
	        return false;
	
	    }
	};
//version1
//class Solution {
//public:
//    bool containsDuplicate(vector<int>& nums)
//    {
//        int n = nums.size();
//        unordered_set<int>aim;
//        for (int i = 0; i < n; i++) 
//        {
//            if (aim.find(nums[i]) == aim.end()) 
//            {
//                aim.insert(nums[i]);
//            }
//            else 
//            {
//                return true;
//            }
//        }
//        return false;
//
//    }
//};
int main() 
{
	return 0;
}