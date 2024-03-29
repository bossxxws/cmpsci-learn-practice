#include <iostream>
#include <queue>
#define x first
#define y second
using namespace std;
typedef pair <int,int> PII;
const int N = 1010;
int n;
int h[N][N];
bool st[N][N];
void bfs (int sx,int sy,bool &has_higher,bool &has_lower) {
    queue <PII> q;
    q.push ({sx,sy});
    while (!q.empty ()) {
        PII t = q.front ();
        q.pop ();
        for (int i = t.x - 1;i <= t.x + 1;i++) {
            for (int j = t.y - 1;j <= t.y + 1;j++) {
                if (i < 1 || i > n || j < 1 || j > n) continue;
                if (h[i][j] != h[t.x][t.y]) {
                    if (h[i][j] > h[t.x][t.y]) has_higher = true;
                    else has_lower = true;
                }
                else if (!st[i][j]) {
                    q.push ({i,j});
                    st[i][j] = true;
                }
            }
        }
    }
}
int main () {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) cin >> h[i][j];
    }
    int peak = 0,valley = 0;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            if (!st[i][j]) {
                bool has_higher = false,has_lower = false;
                bfs (i,j,has_higher,has_lower);
                if (!has_higher) peak++;
                if (!has_lower) valley++;
            }
        }
    }
    cout << peak << ' ' << valley << endl;
    return 0;
}


