#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 999999893;

ll pw(ll b, ll e) { ll r = 1; b %= MOD;
    while (e) { if (e & 1) r = r * b % MOD; b = b * b % MOD; e >>= 1; }
    return r; }

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        ll N; scanf("%lld", &N);
        ll n = N - 1, e = n / 2, f = (n + 1) / 2;
        ll b = (pw(2, f) - 1 + MOD) % MOD;
        ll den = ((pw(2, 2 * e + 1) - b * b % MOD) % MOD + MOD) % MOD;
        printf("%lld\n", b * pw(den, MOD - 2) % MOD);
    }
}
