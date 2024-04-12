#include <bits/stdc++.h>

using namespace std;

const int N = 15;

int n, m;
int r[N][N]; //存放答案的数组
char f[N][N]; //存放棋盘初始状态的数组

bool check2(int x, int y) //判断某个点是否满足条件
{
    if(f[x][y] == '_' || x == 0 || y == 0) return true;

    int cnt = 0;
    int z = f[x][y] - '0';

    for(int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            if(x + i >= 1 && x + i <= n && y + j >= 1 && y + j <= m)
            {
                if(r[x + i][y + j]) cnt++;
            }
        }
    }

    if(cnt == z) return true;
    else return false;
}

bool check1(int row) //判断某一行的所有点是否满足条件
{
    for(int i = 1; i <= m; i++)
    {
        if(!check2(row, i)) return false;
    }
    return true;
}

void work() //找到了答案时，输出整个棋盘的像素状态
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            printf("%d", r[i][j]);
        }
        puts("");
    }

    return;
}

void dfs(int x, int y) //用递归遍历整个棋盘的所有点，每个点有两种状态，0表示白，1表示黑
{
    if(x == n && y == m) //如果枚举到最后一个点，判断是否找到了答案
    {
        if(x > 1)
        {
            if(check2(x - 1, y - 1) && check2(x - 1, y) && check1(x)) work();
        }else{
            if(check1(x)) work();
        }
        return;
    }

    if(x > 1 && y > 1)
    {
        if(check2(x - 1, y - 1))
        {
            if(y == m)
            {
                if(check2(x - 1, y))
                {
                    r[x + 1][1] = 0;
                    dfs(x + 1, 1);
                    r[x + 1][1] = 1;
                    dfs(x + 1, 1);
                }
            }else{
                r[x][y + 1] = 0;
                dfs(x, y + 1);
                r[x][y + 1] = 1;
                dfs(x, y + 1);
            }
        }
    }else{
        if(y == m)
        {
            r[x + 1][1] = 0;
            dfs(x + 1, 1);
            r[x + 1][1] = 1;
            dfs(x + 1, 1);
        }else{
            r[x][y + 1] = 0;
            dfs(x, y + 1);
            r[x][y + 1] = 1;
            dfs(x, y + 1);
        }
    }

    return;
}

int main()
{
    cin >> n >> m;
    getchar();
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            scanf("%c", &f[i][j]);
        }
        getchar();
    }

    dfs(1, 0);

    return 0;
}
