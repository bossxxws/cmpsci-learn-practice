#include <bits/stdc++.h>
using namespace std;
int t, n, h, r, f[1010];
double x[1010], y[1010], z[1010];

inline double dist(double X1, double X2, double Y1, double Y2, double Z1, double Z2) 
{
    return sqrt((X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2) + (Z1 - Z2) * (Z1 - Z2));
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &h, &r);
        for (int i = 1; i <= n; i++) scanf("%lf%lf%lf", &x[i], &y[i], &z[i]), f[i] = 0;
        queue<int> q; bool ok = 0;
        for (int i = 1; i <= n; i++) 
            if (z[i] <= r) q.push(i), f[i] = 1;
        while (q.size()) {
            int p = q.front(); q.pop();
            if (ok) break;
            if (z[p] + r >= h) {ok = 1; puts("Yes"); break;}
            for (int i = 1; i <= n; i++) {
                if (f[i]) continue;
                if (dist(x[p], x[i], y[p], y[i], z[p], z[i]) <= 2 * r) {
                    q.push(i), f[i] = 1;
                    if (z[i] + r >= h) {ok = 1; puts("Yes"); break;}
                }
            }
        }
        if (!ok) puts("No");
    }
    return 0;
}

