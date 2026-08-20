#include <iostream>

using namespace std;

const int MOD = 998244353;

// A + B * sqrt(2) 형태를 나타내는 구조체
struct Num {
    long long A, B;
    Num(long long _A = 0, long long _B = 0) {
        A = (_A % MOD + MOD) % MOD;
        B = (_B % MOD + MOD) % MOD;
    }
    Num operator+(const Num& o) const { return Num(A + o.A, B + o.B); }
    Num operator-(const Num& o) const { return Num(A - o.A, B - o.B); }
    Num operator*(const Num& o) const {
        return Num(A * o.A + 2LL * B * o.B, A * o.B + B * o.A);
    }
};

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) { return power(n, MOD - 2); }

// (A + B*sqrt(2)) 의 모듈로 역원 계산
Num inv(const Num& num) {
    long long den = (num.A * num.A % MOD - 2LL * num.B * num.B % MOD) % MOD;
    den = (den + MOD) % MOD;
    long long denInv = modInverse(den);
    return Num(num.A * denInv, -num.B * denInv);
}

// 분할 정복을 이용한 구조체 거듭제곱
Num power(Num base, long long exp) {
    Num res(1, 0);
    while (exp > 0) {
        if (exp % 2 == 1) res = res * base;
        base = base * base;
        exp /= 2;
    }
    return res;
}

void solve() {
    long long n;
    cin >> n;
    long long q = n - 1;
    
    Num R(0, 1); 
    Num R_q = power(R, q);
    Num R_qp1 = R_q * R;
    
    Num num = R_qp1 + R_q - R - Num(1, 0);
    Num den = R_qp1 + R_q - Num(1, 0);
    
    Num ans = num * inv(den);
    cout << ans.A << " " << ans.B << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) solve();
    }
    return 0;
}
