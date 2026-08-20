// Day4 - 코드포스 300C : Beautiful Numbers
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1000000007LL;

// 빠른 거듭제곱
ll mod_pow(ll base, ll exponent) {
    ll result = 1;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = result * base % MOD;
        }

        base = base * base % MOD;
        exponent /= 2;
    }

    return result;
}

// nCk mod MOD
ll combination(const vector<ll>& factorial,
               const vector<ll>& inverse_factorial,
               int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }

    return factorial[n]
         * inverse_factorial[k] % MOD
         * inverse_factorial[n - k] % MOD;
}

// 어떤 수가 a와 b의 숫자만으로 이루어졌는지 확인
bool is_good(ll number, int a, int b) {
    while (number > 0) {
        int digit = number % 10;

        if (digit != a && digit != b) {
            return false;
        }

        number /= 10;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, n;
    cin >> a >> b >> n;

    vector<ll> factorial(n + 1);
    vector<ll> inverse_factorial(n + 1);

    // factorial[i] = i! mod MOD
    factorial[0] = 1;

    for (int i = 1; i <= n; i++) {
        factorial[i] = factorial[i - 1] * i % MOD;
    }

    // inverse_factorial[n] = (n!)^(-1) mod MOD
    inverse_factorial[n] = mod_pow(factorial[n], MOD - 2);

    for (int i = n; i >= 1; i--) {
        inverse_factorial[i - 1] =
            inverse_factorial[i] * i % MOD;
    }

    ll answer = 0;

    for (int countB = 0; countB <= n; countB++) {
        ll digitSum =
            1LL * a * (n - countB)
            + 1LL * b * countB;

        if (is_good(digitSum, a, b)) {
            answer += combination(
                factorial,
                inverse_factorial,
                n,
                countB
            );

            answer %= MOD;
        }
    }

    cout << answer << '\n';

    return 0;
}
