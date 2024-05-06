#include <iostream>

using namespace std;

const int N = 3010;

int n;
int a[N], b[N];
int f[N][N];

int main()
{
    //input
    cin >> n;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    for (int i = 1; i <= n; ++ i) cin >> b[i];

    //dp
    for (int i = 1; i <= n; ++ i)
    {
        int maxv = 1;
        for (int j = 1; j <= n; ++ j)
        {
            f[i][j] = f[i - 1][j];
            if (b[j] == a[i]) f[i][j] = max(f[i][j], maxv);//°üº¬a[i] 
            if (b[j] < a[i]) maxv = max(maxv, f[i - 1][j] + 1); //²»°üº¬a[i] 
        }
    }

    //find result
    int res = 0;
    for (int i = 0; i <= n; ++ i) res = max(res, f[n][i]);
    cout << res << endl;

    return 0;
}


