#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize(2)
#pragma GCC optimize(3)
int e[1002][1002];
int ds[1002], dt[1002];
bitset<1000> bs[1000][2];
struct Node {
    int v, d;
    Node () {}
    Node (int a, int b) {v = a; d = b;}
    friend bool operator < (const Node &a, const Node &b) {
        return a.d > b.d;
    }
};
int main(){
    int n, k, m, a, b, c;
    cin >> n >> k >> m;
    memset(e, -1, sizeof(e));
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        e[a][b] = e[b][a] = c;
    }
    for (int i = 0; i < n; i++) e[i][i] = 0;
    //求所有点到0，n-1的最短路
    bool bd[1002] = {0};
    priority_queue<Node> q;
    q.push(Node(0, 0));
    while (!q.empty()) {
        Node t = q.top();
        q.pop();
        if (bd[t.v] == 1) continue;
        bd[t.v] = 1;
        for (int i = 0; i < n; i++) {
            if (!bd[i] && e[t.v][i] > 0) {
                if (ds[i] == 0 || ds[t.v] + e[t.v][i] < ds[i]) {
                    ds[i] = ds[t.v] + e[t.v][i];
                    q.push(Node(i, ds[i]));
                }
            }
        }
    }
    memset(bd, 0, sizeof(bd));
    q.push(Node(n-1, 0));
    while (!q.empty()) {
        Node t = q.top();
        q.pop();
        if (bd[t.v] == 1) continue;
        bd[t.v] = 1;
        for (int i = 0; i < n; i++) {
            if (!bd[i] && e[t.v][i] > 0) {
                if (dt[i] == 0 || dt[t.v] + e[t.v][i] < dt[i]) {
                    dt[i] = dt[t.v] + e[t.v][i];
                    q.push(Node(i, dt[i]));
                }
            }
        }
    }
    //计算所有点走k步能到达的点
    int ans = ds[n-1];
    for (int i = 0; i < n; i++) {
        bs[i][0][i] = 1;
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            for (int t = 0; t < n; t++) {
                if(e[j][t]>0) bs[j][(i+1)%2] |= bs[t][i%2];
            }
        }
    }
    //枚举所有i,j，点i走k步能到达j，ans = min(0~i最短路 + j~n-1最短路)
    for (int i = 0; i < n; i++) {
        if (ds[i] >= ans) continue;
        if (ds[i] == 0 && dt[i] == 0) continue;
        for (int p = i + 1; p < n; p++) {
            if (!(bs[i][k%2][p] == 0)) {
                ans = min(ans, ds[i] + dt[p]);
            }
        }
    }
    cout << ans;
    return 0;
}


