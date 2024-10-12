#include <iostream>

using namespace std;

int n, m;

const int N = 103;

int x[N], y[N];

int dx[N], dy[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> dx[i] >> dy[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> x[i] >> y[i];
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            x[i] += dx[j];
            y[i] += dy[j];
        }
        cout << x[i] << " " << y[i] << endl;
    }

    return 0;
}