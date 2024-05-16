#include<bits/stdc++.h>

using namespace std;
const int N = 1005, M = 505, S = 105;
int n, m, K, w[S], v[S], f[N][M];
int main() {
    //memset(f, 0xcf, sizeof f);
    scanf("%d%d%d", &n, &m, &K);
    for(int i = 1; i <= K; i++)
        scanf("%d%d", w + i, v + i);

    //f[0][0] = 0;
    for(int i = 1; i <= K; i++) {
        for(int j = n; j >= w[i]; j--) 
            for(int k = m; k >= v[i]; k--)
                f[j][k] = max(f[j][k], f[j - w[i]][k - v[i]] + 1);
    }
    
    int res = -1, t;
    for(int j = 0; j <= n; j++) {
        for(int k = 0; k < m; k++) {
            if(f[j][k] > res || (res == f[j][k] && k < t)) {
                res = f[j][k], t = k;
            }
        }
    }
    printf("%d %d\n", res, m - t);
    return 0;
}


