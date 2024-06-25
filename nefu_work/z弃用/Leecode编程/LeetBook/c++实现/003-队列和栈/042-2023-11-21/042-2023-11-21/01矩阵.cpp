#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
#include<map>
class Solution {
private:
    static constexpr int dirs[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dist(m, vector<int>(n));
        vector<vector<int>> seen(m, vector<int>(n));
        queue<pair<int, int>> q;
        // 将所有的 0 添加进初始队列中
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    q.emplace(i, j);
                    seen[i][j] = 1;
                }
            }
        }

        // 广度优先搜索
        while (!q.empty())
        {
            auto [i,j] = q.front();//split the element in i and j
            q.pop();
            for (int d = 0; d < 4; ++d) 
            {
                int ni = i + dirs[d][0];
                int nj = j + dirs[d][1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && !seen[ni][nj])//!seenp[ni][nj] means we havn't went to this position
                {
                    dist[ni][nj] = dist[i][j] + 1;
                    q.emplace(ni, nj);
                    seen[ni][nj] = 1;
                }
            }
        }

        return dist;
    }
};

int main() 
{
    std::map<std::string, int> scores;
    scores.insert(std::make_pair("Alice", 90));
    scores.insert(std::make_pair("Bob", 85));
    pair p1 = make_pair("zhangao","lichenyang");
    // 通过键访问值
    int aliceScore = scores["Alice"];
    cout << aliceScore << endl;
    cout <<  "yes" << endl;

	
	return 0;
}