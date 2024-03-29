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
    bool col[10][10];
    bool row[10][10];
    bool area[10][10];


    //分成九个小的九宫格
    //九宫格和行列的关系如下
    //idx=【i/3】∗3+【j/3】,
    bool isValidSudoku(vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')continue;
                int idx = i / 3 * 3 + j / 3;
                int number = board[i][j] - '0';
                if (col[j][number] || row[i][number] || area[idx][number])return false;
                col[j][number] = row[i][number] = area[idx][number] = true;
            }
        }
        return true;
    }
};
int main() 
{

	return 0;
}