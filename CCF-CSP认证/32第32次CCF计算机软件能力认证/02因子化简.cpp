#include <iostream>
#include <unordered_map>
using namespace std;

typedef long long LL;

LL n;     // n<=1e10
int k, q; // k,q<=10;

unordered_map<LL, LL> primes;

LL quickmi(LL a, int k)
{
    LL res = 1;
    // cout << "K " << k << endl;
    while (k)
    {
        // cout << "K&1: " << bool(k & 1);
        if (k & 1)
            res = res * a;
        k >>= 1;
        a = a * a;
    }
    // cout << a << endl;
    return res;
}

LL work(LL n, int k)
{
    // 清空 primes
    primes.clear();
    // 把n化为多个质数的幂和
    for (LL i = 2; i <= n / i; i++)
    {
        while (n % i == 0)
        {
            primes[i]++;
            n /= i;
        }
    }
    //  cout << primes[5] << endl;
    //  根号n另一端也可能存在一个较大的质因数，也算上
    //  或者说特殊的也算上（5没有质因数，它本身就是一个质数）
    if (n > 1)
    {
        primes[n]++;
    }

    // 收集完毕，接下来验证幂与k的大小关系

    LL res = 1;
    for (auto prime : primes)
    {
        if (prime.second >= k) // 认为该因子重要
        {
            // cout << "second " << prime.second << endl;
            // cout << "piece: " << prime.first << " " << prime.second << " " << quickmi(prime.first, prime.second) << endl;
            res *= quickmi(prime.first, prime.second);
        }
    }
    return res;
}

int main()
{
    cin >> q;

    while (q--)
    {
        cin >> n >> k;
        // cout << n << endl;

        cout << work(n, k) << endl;
    }
    // cout << quickmi(2, 4) << endl;
    return 0;
}