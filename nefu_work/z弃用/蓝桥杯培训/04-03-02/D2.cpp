#include<bits/stdc++.h>
using namespace std;
int mov[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int vis[1005][1005];
int answ[1005][1005];//记录对应位置的答案
char mp[1005][1005];
int n, m;
int ans;
int ct;
struct node
{
    char now;
    int x, y;
} fst, sec;
queue<node> q;
void bfs()
{
    while (!q.empty())
    {

        ans++;
        fst = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int xx = fst.x + mov[i][0];
            int yy = fst.y + mov[i][1];
            if (xx < 1 || xx > n || yy < 1 || yy > n || mp[fst.x][fst.y] == mp[xx][yy] || vis[xx][yy] == ct)
                continue;
            vis[xx][yy] = ct;
            sec.now = mp[xx][yy];
            sec.x = xx;
            sec.y = yy;
            q.push(sec);
        }
    }
}
void dfs(int x, int y)
{
    answ[x][y] = ans;
    for (int i = 0; i < 4; i++)
    {
        int xx = x + mov[i][0];
        int yy = y + mov[i][1];
        if (xx < 1 || xx > n || yy < 1 || yy > n || vis[xx][yy] != ct)
            continue;
        vis[xx][yy] = 0;
        dfs(xx, yy);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> mp[i] + 1;
    while (m--)
    {
        ct++;
        ans = 0;
        int a, b;
        cin >> a >> b;
        if (answ[a][b] != 0)
            cout << answ[a][b] << endl;
        else
        {
            while (!q.empty())
                q.pop();
            fst.now = mp[a][b];
            fst.x = a;
            fst.y = b;
            q.push(fst);
            vis[a][b] = ct;
            bfs();
            dfs(a, b);
            cout << ans << endl;
        }
    }
    return 0;
}


