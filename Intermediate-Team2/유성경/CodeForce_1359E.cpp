// CodeForce 1359E. Modular Stability
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 998244353;

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

long long nCr(int n, int r, const vector<long long>& fact, const vector<long long>& invFact)
{
    if (r < 0 || r > n)
    {
        return 0;
    }

    long long res = fact[n] * invFact[r];
    res %= MOD;
    res *= invFact[n - r];
    res %= MOD;

    return res;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

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

    for (int i = 1; i <= n; ++i)
    {
        int multiples = n / i;
        int remaining = multiples - 1;

        if (remaining >= k - 1)
        {
            ans = (ans + nCr(remaining, k - 1, fact, invFact)) % MOD;
        }
    }

    cout << ans << "\n";

    return 0;
}
#endif