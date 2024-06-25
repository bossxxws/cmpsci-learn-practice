#include <iostream>
using namespace std;
#include<vector>

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> result(rowIndex + 1, 1);
        if (rowIndex < 2)
        {
            return result;
        }
        // 需要进行迭代的次数
        for (int i = 1; i < rowIndex; i++)
        {
            // 每次迭代进行的计算
            for (int j = i; j > 0; j--)
            {
                result[j] = result[j] + result[j - 1];
            }
        }
        return result;
    }
};

int main()
{

	system("pause");

	return 0;
}