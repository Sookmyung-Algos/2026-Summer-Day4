#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

const ll MOD = 1000000007;

ll modPow(ll a, ll b) {
    ll result = 1;

    while (b > 0) {
        if (b % 2 == 1) {
            result = result * a % MOD;
        }

        a = a * a % MOD;
        b /= 2;
    }

    return result;
}

bool isGood(int x, int a, int b) {
    while (x > 0) {
        int digit = x % 10;

        if (digit != a && digit != b) {
            return false;
        }

        x /= 10;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, n;
    cin >> a >> b >> n;

    vector<ll> fact(n + 1);
    vector<ll> invFact(n + 1);

    fact[0] = 1;

    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    invFact[n] = modPow(fact[n], MOD - 2);

    for (int i = n - 1; i >= 0; i--) {
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }

    ll answer = 0;

    for (int k = 0; k <= n; k++) {
        int sum = a * k + b * (n - k);

        if (isGood(sum, a, b)) {
            ll comb = fact[n];
            comb = comb * invFact[k] % MOD;
            comb = comb * invFact[n - k] % MOD;

            answer = (answer + comb) % MOD;
        }
    }

    cout << answer << '\n';

    return 0;
}