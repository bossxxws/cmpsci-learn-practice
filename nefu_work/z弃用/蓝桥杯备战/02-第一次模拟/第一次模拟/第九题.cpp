/*
��������
����С��վ��һ�� n �� m �еķ���ͼ�м䣬����ͼ��ÿһ�������϶�����һ����������
��������������ڷ������������ĸ��������ڣ��ڵ��������Լ������ 1 ������Դ�����һ�������ƶ�����һ�����񣬵�ȻҲ���Դ���һ�������ƻص�һ������
��������С����ʼʱվ�ڵ� r �е� c �У�����С�������ƶ�������ͼ�ڵĶ��ٸ�����
�����ʽ
��������ĵ�һ�а����������� n, m ����һ���ո�ָ�����ʾ����ͼ��������������
���������� n �У�ÿ�а��� m ����������������������һ���ո�ָ������α�ʾ����ͼ�дӵ� 1 �е��� n �У�ÿ�дӵ� 1 �е��� m ���е�����
����������һ�а����������� r, c����һ���ո�ָ�����ʾС�����ڵ��кź��кš�
�����ʽ
�������һ�а���һ����������ʾ�𰸡�
��������
3 4
3 6 5 5
2 4 3 5
7 8 3 8
3 2
�������
5
����������ģ��Լ��
��������50%������������1 <= n, m <= 100������ͼ�е�ÿ���������� 10**5 ��10��5�η�����
����������������������1 <= n, m <= 1000������ͼ�е�ÿ���������� 10**9 ��10��9�η�����
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
