#include <bits/stdc++.h>
using namespace std;
 
const long long MOD = 998244353;
 
long long power(long long a, long long b) {
    long long ret = 1;
 
    while (b > 0) {
        if (b % 2 == 1)
            ret = ret * a % MOD;
 
        a = a * a % MOD;
        b /= 2;
    }
 
    return ret;
}
 
int main() {
    int n, k;
    cin >> n >> k;
 
    vector<long long> fac(n + 1);
    vector<long long> inv(n + 1);
 
    fac[0] = 1;
 
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % MOD;
 
    inv[n] = power(fac[n], MOD - 2);
 
    for (int i = n; i >= 1; i--)
        inv[i - 1] = inv[i] * i % MOD;
 
    long long ans = 0;
 
    for (int i = 1; i <= n; i++) {
        int cnt = n / i - 1;
 
        if (cnt < k - 1)
            continue;
 
        long long now = fac[cnt];
        now = now * inv[k - 1] % MOD;
        now = now * inv[cnt - (k - 1)] % MOD;
 
        ans += now;
        ans %= MOD;
    }
 
    cout << ans;
 
    return 0;
}
