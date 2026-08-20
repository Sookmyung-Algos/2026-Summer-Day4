#include <bits/stdc++.h>
using namespace std;
 
long long egcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
 
    long long x1, y1;
    long long g = egcd(b, a % b, x1, y1);
 
    x = y1;
    y = x1 - (a / b) * y1;
 
    return g;
}
 
int main() {
    long long A, B, C;
    cin >> A >> B >> C;
 
    long long x, y;
 
    long long a = abs(A);
    long long b = abs(B);
 
    long long g = egcd(a, b, x, y);
 
    long long c = -C;
 
    if (c % g != 0) {
        cout << -1;
        return 0;
    }
 
    x *= c / g;
    y *= c / g;
 
    if (A < 0) x = -x;
    if (B < 0) y = -y;
 
    cout << x << " " << y;
 
    return 0;
}
