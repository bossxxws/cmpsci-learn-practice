#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1010;

int n;
bool f[N][N];
int h[N][N];
//　将两个需要返回的参数，设置为全局变量，则可以正常通过此题。
//  将两个需要返回的参数，设置为带地址符的变量，则MLE
bool has_higher, has_lower;
//  657 ms
void dfs(int sx, int sy) {
    f[sx][sy] = true;
    for (int x = sx - 1; x <= sx + 1; x++) {
        for (int y = sy - 1; y <= sy + 1; y++) {
            if (x < 0 || x >= n || y < 0 || y >= n) continue;
            if (h[sx][sy] != h[x][y]) { //高度不相等
                if (h[sx][sy] < h[x][y]) has_higher = true;
                if (h[sx][sy] > h[x][y]) has_lower = true;
            } else { //高度相等
                if (f[x][y]) continue;
                dfs(x, y);
            }
        }
    }
}
int vally, peak;
int main() {
    //加快读入
    cin.tie(0), ios::sync_with_stdio(false);
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> h[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!f[i][j]) {
                has_higher = has_lower = false;
                dfs(i, j);
                if (has_higher && has_lower) continue;
                if (has_higher) vally++;
                if (has_lower) peak++;
            }
        }
    }

    //对于不存在山峰+山谷的一马平地，山峰山谷都输出1
    if (peak == 0 && vally == 0) peak = 1, vally = 1;
    printf("%d %d\n", peak, vally);
    return 0;
}


