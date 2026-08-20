// Day4 - 코드포스 7C : Line
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// a*x + b*y = gcd(a, b)
ll extended_gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1;
    ll g = extended_gcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return g;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll A, B, C;
    cin >> A >> B >> C;

    ll a = abs(A);
    ll b = abs(B);

    ll x, y;
    ll g = extended_gcd(a, b, x, y);

    // 절댓값으로 계산했으므로 원래 계수의 부호를 복구
    if (A < 0) x = -x;
    if (B < 0) y = -y;

    // A*x + B*y = -C가 정수해를 가지는지 확인
    if ((-C) % g != 0) {
        cout << -1 << '\n';
        return 0;
    }

    ll k = (-C) / g;

    x *= k;
    y *= k;

    // 문제에서 요구하는 범위 확인
    if (x < -5000000000000000000LL ||
        x >  5000000000000000000LL ||
        y < -5000000000000000000LL ||
        y >  5000000000000000000LL) {
        cout << -1 << '\n';
        return 0;
    }

    cout << x << ' ' << y << '\n';

    return 0;
}
