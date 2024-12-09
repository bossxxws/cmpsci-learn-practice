#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

const int N = 1e3 + 5;

typedef pair<int, int> PII;

int n, k, t, xl, yd, xr, yu;

PII d[25][N];

int cnt[N];

bool isin(int x, int y)
{
	return x >= xl && x <= xr && y >= yd && y <= yu;
}

int main()
{
	cin >> n >> k >> t >> xl >> yd >> xr >> yu;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= t; j++)
		{
			scanf("%d%d", &d[i][j].first, &d[i][j].second);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= t; j++)
		{
			int cnter = 0;
			while (j <= t)
			{
				if (isin(d[i][j].first, d[i][j].second))
				{
					cnter++;
					j++;
				}
				else
				{
					break;
				}
			}
			cnt[i] = max(cnt[i], cnter);
		}
	}

	int r1 = 0, r2 = 0;
	for (int i = 1; i <= n; i++)
	{
		if (cnt[i])
		{
			r1++;
			if (cnt[i] >= k)
			{
				r2++;
			}
		}
	}

	cout << cnt[1] << endl;
	cout << r1 << endl
		 << r2;

	return 0; //
}
