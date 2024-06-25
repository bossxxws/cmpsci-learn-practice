#include <iostream>
using namespace std;
#include<vector>
//1 ¶ş·Ö²éÕÒ
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else if (nums[mid] == target) {
                return mid;
            }
        }
        return left;
    }
};

//2
class Solution
{
public:
    int searchInsert(std::vector<int>& nums, int target)
    {
        int insertPos = 0;

        while (insertPos < nums.size() && nums[insertPos] < target)
        {
            insertPos++;
        }

        return insertPos;
    }
};

int main()
{

	system("pause");

	return 0;
}