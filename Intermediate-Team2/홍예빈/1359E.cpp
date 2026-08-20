// Day4 - 코드포스 1359E : Modular Stability
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 998244353;

// 빠른 거듭제곱
ll modPow(ll base, ll exponent) {
    ll result = 1;

    while (exponent > 0) {
        if (exponent & 1) {
            result = result * base % MOD;
        }

        base = base * base % MOD;
        exponent >>= 1;
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    // 원소를 k개 고를 수 없으면 답은 0
    if (k > n) {
        cout << 0 << '\n';
        return 0;
    }

    vector<ll> factorial(n + 1);
    vector<ll> inverseFactorial(n + 1);

    factorial[0] = 1;

    for (int i = 1; i <= n; i++) {
        factorial[i] = factorial[i - 1] * i % MOD;
    }

    inverseFactorial[n] = modPow(factorial[n], MOD - 2);

    for (int i = n; i >= 1; i--) {
        inverseFactorial[i - 1] =
            inverseFactorial[i] * i % MOD;
    }

    auto combination = [&](int N, int R) -> ll {
        if (R < 0 || R > N) {
            return 0;
        }

        return factorial[N]
             * inverseFactorial[R] % MOD
             * inverseFactorial[N - R] % MOD;
    };

    ll answer = 0;

    for (int first = 1; first <= n; first++) {
        int multipleCount = n / first;

        if (multipleCount < k) {
            continue;
        }

        // first는 이미 선택했으므로 나머지 k-1개를 선택
        answer += combination(multipleCount - 1, k - 1);
        answer %= MOD;
    }

    cout << answer << '\n';

    return 0;
}
