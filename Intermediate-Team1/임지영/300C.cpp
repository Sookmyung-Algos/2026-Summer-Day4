#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007; // 문제에서 요구하는 모듈러

int a, b, n; // a, b: 좋아하는 두 자릿수, n: 만들 숫자의 자릿수 길이

// fact[i]: i! mod MOD 값을 미리 저장해두는 배열
// invFact[i]: (i!)의 모듈러 역원을 미리 저장해두는 배열
vector<ll> fact, invFact;

// x^y mod MOD 를 빠르게 계산하는 분할거듭제곱(fast power) 함수
ll power(ll x, ll y){
    x %= MOD;
    ll result = 1;

    while (y > 0){
        // y의 최하위 비트가 1이면 결과에 x를 곱해준다
        if (y & 1) result = result * x % MOD;

        // x를 제곱하고 y를 절반으로 줄여가며 반복
        x = x * x % MOD;
        y >>= 1;
    }

    return result;
}

// 0! 부터 maxN! 까지, 그리고 그 역원까지 전처리하는 함수
void precomputeFactorials(int maxN){
    fact.resize(maxN + 1);
    invFact.resize(maxN + 1);

    fact[0] = 1;
    for (int i = 1; i <= maxN; i++){
        fact[i] = fact[i - 1] * i % MOD;
    }

    // 페르마 소정리를 이용해 fact[maxN]의 역원을 구하고
    // 거꾸로 내려오면서 나머지 역팩토리얼 값들을 채운다
    invFact[maxN] = power(fact[maxN], MOD - 2);
    for (int i = maxN; i > 0; i--){
        invFact[i - 1] = invFact[i] * i % MOD;
    }
}

// 조합수 C(total, choose) mod MOD 를 계산하는 함수
ll combination(int total, int choose){
    if (choose < 0 || total < 0 || choose > total) return 0;
    return fact[total] * invFact[choose] % MOD * invFact[total - choose] % MOD;
}

// 어떤 정수 num의 모든 자릿수가 a 또는 b로만 이루어져 있는지 검사하는 함수
// (num이 0이면 애초에 자릿수가 없으므로 false로 처리)
bool isGoodNumber(ll num){
    if (num <= 0) return false;

    while (num > 0){
        int digit = num % 10;
        if (digit != a && digit != b) return false;
        num /= 10;
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b >> n;

    // 조합 계산에 필요한 최대 값(n)까지 팩토리얼 전처리
    precomputeFactorials(n);

    ll answer = 0;

    // x: n자리 숫자 중에서 숫자 a를 사용한 개수 (나머지 n-x자리는 b)
    // 이때 각 자리 숫자들의 합 = x*a + (n-x)*b
    for (int x = 0; x <= n; x++){
        ll digitSum = (ll)x * a + (ll)(n - x) * b;

        // 자릿수 합(digitSum)이 good number이면(즉, a와 b로만 구성되면)
        // 이 숫자는 excellent number이므로, 해당 자리 배치 경우의 수(조합)를 답에 누적
        if (isGoodNumber(digitSum)){
            answer = (answer + combination(n, x)) % MOD;
        }
    }

    cout << answer << "\n";

    return 0;
}