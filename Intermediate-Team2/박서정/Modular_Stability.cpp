#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 998244353;
const int MAXN = 500000;

ll fact[MAXN + 1];
ll invfact[MAXN + 1];

ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

ll comb(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    invfact[n] = power(fact[n], MOD - 2);

    for (int i = n; i >= 1; i--) {
        invfact[i - 1] = invfact[i] * i % MOD;
    }

    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        int cnt = n / i - 1;
        if (cnt < k - 1) break;

        ans += comb(cnt, k - 1);
        ans %= MOD;
    }

    cout << ans << '\n';

    return 0;
}