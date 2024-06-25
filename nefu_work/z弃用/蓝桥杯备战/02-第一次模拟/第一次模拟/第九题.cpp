/*
问题描述
　　小蓝站在一个 n 行 m 列的方格图中间，方格图的每一个方格上都标有一个正整数。
　　如果两个相邻方格（上下左右四个方向相邻）内的数的最大公约数大于 1 ，则可以从其中一个方格移动到另一个方格，当然也可以从另一个方格移回第一个方格。
　　假设小蓝开始时站在第 r 行第 c 列，请问小蓝可以移动到方格图内的多少个方格？
输入格式
　　输入的第一行包含两个整数 n, m ，用一个空格分隔，表示方格图的行数和列数。
　　接下来 n 行，每行包含 m 个正整数，相邻整数间用一个空格分隔，依次表示方格图中从第 1 行到第 n 行，每行从第 1 列到第 m 列中的数。
　　接下来一行包含两个整数 r, c，用一个空格分隔，表示小蓝所在的行号和列号。
输出格式
　　输出一行包含一个整数，表示答案。
样例输入
3 4
3 6 5 5
2 4 3 5
7 8 3 8
3 2
样例输出
5
评测用例规模与约定
　　对于50%的评测用例，1 <= n, m <= 100，方格图中的每个数不超过 10**5 （10的5次方）。
　　对于所有评测用例，1 <= n, m <= 1000，方格图中的每个数不超过 10**9 （10的9次方）。
*/
#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void dfs(const vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c, int& count) {
    int n = grid.size();
    int m = grid[0].size();

    if (r >= 0 && r < n && c >= 0 && c < m && !visited[r][c]) {
        visited[r][c] = true;
        count++;
        int dr[] = { -1, 1, 0, 0 };
        int dc[] = { 0, 0, -1, 1 };
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] &&
                gcd(grid[r][c], grid[nr][nc]) > 1) {
                dfs(grid, visited, nr, nc, count);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int r, c;
    cin >> r >> c;

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int count = 0;
    dfs(grid, visited, r - 1, c - 1, count);

    cout << count << endl;

    return 0;
}
