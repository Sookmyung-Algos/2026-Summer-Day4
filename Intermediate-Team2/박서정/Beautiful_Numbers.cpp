#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1000000007;

ll modPow(ll a, ll b) {
    ll res = 1;

    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }

    return res;
}

bool good(int x, int a, int b) {
    while (x) {
        int d = x % 10;

        if (d != a && d != b) return false;

        x /= 10;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, n;
    cin >> a >> b >> n;

    vector<ll> fact(n + 1), invFact(n + 1);

    fact[0] = 1;

    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    invFact[n] = modPow(fact[n], MOD - 2);

    for (int i = n; i >= 1; i--) {
        invFact[i - 1] = invFact[i] * i % MOD;
    }

    ll ans = 0;

    for (int i = 0; i <= n; i++) {
        int sum = a * i + b * (n - i);

        if (good(sum, a, b)) {
            ll comb = fact[n] * invFact[i] % MOD * invFact[n - i] % MOD;
            ans = (ans + comb) % MOD;
        }
    }

    cout << ans << '\n';

    return 0;
}