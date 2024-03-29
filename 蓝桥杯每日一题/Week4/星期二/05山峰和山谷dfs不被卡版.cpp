#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1010;

int n;
bool f[N][N];
int h[N][N];
//����������Ҫ���صĲ���������Ϊȫ�ֱ��������������ͨ�����⡣
//  ��������Ҫ���صĲ���������Ϊ����ַ���ı�������MLE
bool has_higher, has_lower;
//  657 ms
void dfs(int sx, int sy) {
    f[sx][sy] = true;
    for (int x = sx - 1; x <= sx + 1; x++) {
        for (int y = sy - 1; y <= sy + 1; y++) {
            if (x < 0 || x >= n || y < 0 || y >= n) continue;
            if (h[sx][sy] != h[x][y]) { //�߶Ȳ����
                if (h[sx][sy] < h[x][y]) has_higher = true;
                if (h[sx][sy] > h[x][y]) has_lower = true;
            } else { //�߶����
                if (f[x][y]) continue;
                dfs(x, y);
            }
        }
    }
}
int vally, peak;
int main() {
    //�ӿ����
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

    //���ڲ�����ɽ��+ɽ�ȵ�һ��ƽ�أ�ɽ��ɽ�ȶ����1
    if (peak == 0 && vally == 0) peak = 1, vally = 1;
    printf("%d %d\n", peak, vally);
    return 0;
}


