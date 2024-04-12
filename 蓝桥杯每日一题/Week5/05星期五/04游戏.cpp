#include <iostream>
#include <algorithm>
using namespace std;

const int N = 110;
int n;
int w[N], f[N][N];

int main()
{
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) cin >> w[i], sum += w[i];
    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;
            f[i][j] = max(w[i] - f[i + 1][j], w[j] - f[i][j - 1]);
        }
    }
    cout << (sum + f[0][n - 1]) / 2 << ' ' << (sum - f[0][n - 1]) / 2 << endl;
    return 0;
}


