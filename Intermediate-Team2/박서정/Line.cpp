#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll extgcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1;
    ll g = extgcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return g;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll A, B, C;
    cin >> A >> B >> C;

    ll x, y;
    ll g = extgcd(abs(A), abs(B), x, y);

    if ((-C) % g != 0) {
        cout << -1 << '\n';
        return 0;
    }

    ll k = (-C) / g;

    x *= k;
    y *= k;

    if (A < 0) x = -x;
    if (B < 0) y = -y;

    cout << x << ' ' << y << '\n';

    return 0;
}