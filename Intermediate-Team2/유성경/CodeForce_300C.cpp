// CodeForce 300C. Beautiful Numbers
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;

bool isGood(long long num, int a, int b)
{
    while (num > 0)
    {
        int digit = num % 10;

        if (digit != a && digit != b)
        {
            return false;
        }
        num /= 10;
    }

    return true;
}

long long power(long long base, long long exp)
{
    long long res = 1;
    base %= MOD;

    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            res = (res * base) % MOD;
        }

        base = (base * base) % MOD;
        exp /= 2;
    }

    return res;
}

long long modInverse(long long n)
{
    return power(n, MOD - 2);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, n;
    cin >> a >> b >> n;

    vector<long long> fact(n + 1);
    vector<long long> invFact(n + 1);

    fact[0] = 1;
    invFact[0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    invFact[n] = modInverse(fact[n]);

    for (int i = n - 1; i >= 1; --i)
    {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }

    long long ans = 0;

    for (int i = 0; i <= n; ++i)
    {
        long long sum = (long long)a * i + (long long)b * (n - i);

        if (isGood(sum, a, b))
        {
            long long ways = (fact[n] * invFact[i]) % MOD;
            ways = (ways * invFact[n - i]) % MOD;
            ans = (ans + ways) % MOD;
        }
    }

    cout << ans << "\n";

    return 0;
}
#endif