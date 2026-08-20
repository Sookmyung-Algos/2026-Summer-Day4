#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1000005;

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

bool isBeautiful(long long num, int a, int b) {
    while (num > 0) {
        int digit = num % 10;
        if (digit != a && digit != b) return false;
        num /= 10;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a, b, n;
    if (!(cin >> a >> b >> n)) return 0;
    
    precompute();
    
    long long ans = 0;
    for (int i = 0; i <= n; i++) {
        long long sum = (long long)a * i + (long long)b * (n - i);
        if (isBeautiful(sum, a, b)) {
            ans = (ans + nCr(n, i)) % MOD;
        }
    }
    cout << ans << "\n";
    return 0;
}
