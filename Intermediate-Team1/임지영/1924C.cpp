#include <iostream>

using namespace std;
typedef long long ll;

const ll MOD = 999999893; // 문제에서 요구하는 특수 모듈러

// a를 MOD 범위 [0, MOD-1] 안으로 정규화하는 함수
ll norm(ll x){
    x %= MOD;
    if (x < 0) x += MOD;
    return x;
}

// a^b mod MOD 를 빠르게 계산하는 분할거듭제곱(fast power) 함수
ll power(ll a, ll b){
    a = norm(a);
    ll result = 1;

    while (b > 0){
        // b의 최하위 비트가 1이면 결과에 a를 곱해준다
        if (b & 1) result = (ll)((__int128)result * a % MOD);

        // a를 제곱하고 b를 절반으로 줄여가며 반복
        a = (ll)((__int128)a * a % MOD);
        b >>= 1;
    }

    return result;
}

// 페르마 소정리를 이용한 모듈러 역원 계산 (MOD가 소수라고 가정)
ll modInverse(ll a){
    return power(a, MOD - 2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--){
        ll n;
        cin >> n;

        // c: sqrt(2)^floor(N/2) 형태를 표현하기 위한 2의 거듭제곱 값
        // num: B = p/q 로 나타낼 때의 분자(p)에 해당하는 값
        // den: B = p/q 로 나타낼 때의 분모(q)에 해당하는 값
        ll c, num, den;

        if (n % 2 == 0){
            // N이 짝수인 경우: c = 2^(N/2)
            ll m = n / 2;
            c = power(2, m);

            // 분자 계산: -(2c - 2)
            num = norm(-2 * norm(c - 1));

            // 분모 계산: (c-2)^2 - 2
            ll t1 = norm(c - 2);
            den = norm((t1 * t1) % MOD - 2);
        } else {
            // N이 홀수인 경우: c = 2^((N-1)/2)
            ll m = (n - 1) / 2;
            c = power(2, m);

            // 분자 계산: -(c - 1)
            num = norm(-norm(c - 1));

            // 분모 계산: 2 - (c+1)^2
            ll t1 = norm(c + 1);
            den = norm(2 - (t1 * t1) % MOD);
        }

        // 최종 답: p * inv(q) mod MOD
        ll ans = norm((__int128)num * modInverse(den) % MOD);

        cout << ans << "\n";
    }

    return 0;
}