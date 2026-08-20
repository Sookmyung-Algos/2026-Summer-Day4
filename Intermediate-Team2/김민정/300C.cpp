#include <bits/stdc++.h>
using namespace std;
 
const long long MOD = 1000000007;
 
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
 
bool good(int x, int a, int b) {
    while (x > 0) {
        int k = x % 10;
 
        if (k != a && k != b)
            return false;
 
        x /= 10;
    }
 
    return true;
}
 
int main() {
    int a, b, n;
    cin >> a >> b >> n;
 
    vector<long long> fac(n + 1);
    vector<long long> inv(n + 1);
 
    fac[0] = 1;
 
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % MOD;
 
    inv[n] = power(fac[n], MOD - 2);
 
    for (int i = n; i >= 1; i--)
        inv[i - 1] = inv[i] * i % MOD;
 
    long long ans = 0;
 
    for (int i = 0; i <= n; i++) {
        int sum = a * i + b * (n - i);
 
        if (good(sum, a, b)) {
            long long now = fac[n];
            now = now * inv[i] % MOD;
            now = now * inv[n - i] % MOD;
 
            ans += now;
            ans %= MOD;
        }
    }
 
    cout << ans;
 
    return 0;
}
