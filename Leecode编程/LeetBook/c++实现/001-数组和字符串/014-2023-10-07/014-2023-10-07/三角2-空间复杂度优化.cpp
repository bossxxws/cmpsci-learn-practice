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
        // ��Ҫ���е����Ĵ���
        for (int i = 1; i < rowIndex; i++)
        {
            // ÿ�ε������еļ���
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