//#include <iostream>
//using namespace std;
//#include <vector>
//class Solution {
//public:
//    int pivotIndex(vector<int>& nums)
//    {
//        int mini = -1;
//        int len = sizeof(nums) / sizeof(nums[0]);
//        for (int i = 0; i < len; i++)
//        {
//            int sum1 = 0;
//            int sum2 = 0;
//            //计算第i位前面与后面的数的和是否相等，mini计算最小下标
//            for (int j = 0; i < j < len; i++)
//            {
//                sum1 = sum1 + nums[j];
//            }
//            for (int k = 0; 0 < k < i; k++)
//            {
//                sum2 = sum2 + nums[k];
//            }
//            //判断mini是不是-1，如果是-1就换为i，如果不是-1就比大小
//            if (mini == -1 || i < mini)
//            {
//                mini = i;
//            }
//        }
//        cout << mini << endl;
//    }
//};
//int main()
//{
//
//    system("pause");
//
//    return 0;
//}
#include <numeric>
#include <iostream>
using namespace std;
#include <vector>
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (2 * sum + nums[i] == total) {
                return i;
            }
            sum += nums[i];
        }
        return -1;
    }
};

