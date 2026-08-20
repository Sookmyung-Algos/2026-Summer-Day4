#include <iostream>

using namespace std;

const int MOD = 998244353;
const int MAXN = 500005;

long long fact[MAXN], invFact[MAXN];

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

void precompute() {
    fact[0] = 1; invFact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAXN - 1] = modInverse(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    if (!(cin >> n >> k)) return 0;
    
    precompute();
    
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int multiples = n / i;
        if (multiples >= k) {
            ans = (ans + nCr(multiples - 1, k - 1)) % MOD;
        }
    }
    cout << ans << "\n";
    return 0;
}
