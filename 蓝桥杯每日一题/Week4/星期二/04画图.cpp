//注意这里的输入是先输入的是列，然后是行
#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int n, m ,q;

char g[N][N];
bool st[N][N];

void change(int x1, int y1, int x2, int y2){
    if(x1 == x2){// 同一行
        for(int i = y1; i <= y2; i ++){
            if( g[x1][i] == '|'|| g[x1][i] == '+') g[x1][i]= '+';
            else g[x1][i] = '-';
        }
    }
    // 同一列
    else if ( y1 == y2){
        for(int i = x1; i <= x2; i ++){
            if( g[i][y1] == '-' || g[i][y1] == '+') g[i][y1] = '+';
            else g[i][y1] = '|';
        }
    }
}

void paint(int x, int y, char s){
    st[x][y] = true;
    g[x][y] = s;
    int dx[4] = { -1, 0, 1, 0}, dy[4] = { 0, 1, 0, -1};
    for(int i = 0; i < 4; i ++){
        int a = x + dx[i], b = y + dy[i];
        if(a < 0 || a >= n || b < 0 || b >= m || st[a][b]) continue;
        if(g[a][b] == '|' || g[a][b] == '-' || g[a][b] == '+') continue;
        paint(a, b, s);
    }
}
int main(){
    cin >> m >> n >> q;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            g[i][j] = '.';

    while(q --){
        int op;
        cin >> op;
        if(op == 0){
            // x和y反着读入
            int x1, y1, x2, y2;
            cin >> y1 >> x1 >> y2 >> x2;
            if(x1 > x2) swap(x1, x2);
            if(y1 > y2) swap(y1, y2);
            change(x1, y1, x2, y2);
        }
        else{
            int x, y;
            char s;
            // x和y反着读入
            cin >> y >> x >> s;
            memset(st, 0, sizeof st);
            paint(x, y, s);

        }
    }

    for(int i = n -1; i >= 0; i--){
        for(int j = 0; j < m; j++)
            cout << g[i][j];
        cout << endl;
    }
}



