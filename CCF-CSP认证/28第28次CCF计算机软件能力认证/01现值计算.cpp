#include <iostream>

using namespace std;

const int N = 52;

int n;
double I;

double d[N];

double cclt(double a, double k, double I) // 第k年a元的现值
{
    for (int i = k; k >= 1; k--)
    {
        a /= I;
    }
    // cout<<a<<endl;
    return a;
}

int main()
{
    cin >> n >> I;
    // cout<<n<<" "<<I<<endl;
    for (int i = 1; i <= n + 1; i++)
    {
        cin >> d[i];
        // cout<<d[i]<<" "<< endl;
    }

    double k = I + 1;

    double res = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        // cout<<d[i];
        res += cclt(d[i], i - 1, k);
    }

    printf("%.3f", res);
    return 0;
}