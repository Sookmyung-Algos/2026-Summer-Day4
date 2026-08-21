#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const ll MOD = 998244353; // 문제에서 요구하는 모듈러

int n, k; // n: 배열 원소의 최댓값 범위, k: 배열의 길이

// fact[i]: i! mod MOD 값을 미리 저장해두는 배열
// invFact[i]: (i!)의 모듈러 역원을 미리 저장해두는 배열
vector<ll> fact, invFact;

// a^b mod MOD 를 빠르게 계산하는 분할거듭제곱(fast power) 함수
ll power(ll a, ll b){
    a %= MOD;
    ll result = 1;

    while (b > 0){
        // b의 최하위 비트가 1이면 결과에 a를 곱해준다
        if (b & 1) result = result * a % MOD;

        // a를 제곱하고 b를 절반으로 줄여가며 반복
        a = a * a % MOD;
        b >>= 1;
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
// 범위를 벗어나면(선택할 개수가 더 많으면) 0을 반환
ll combination(int total, int choose){
    if (choose < 0 || total < 0 || choose > total) return 0;
    return fact[total] * invFact[choose] % MOD * invFact[total - choose] % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    // 조합 계산에 필요한 최대 값(n)까지 팩토리얼 전처리
    precomputeFactorials(n);

    ll answer = 0;

    // d: 배열에서 가장 작은 원소(a1) 후보값
    // stable 배열이 되려면 a1이 나머지 모든 원소를 나눠야 하므로,
    // 나머지 (k-1)개는 (d, n] 구간에 있는 d의 배수들 중에서 골라야 한다
    for (int d = 1; d <= n; d++){
        // d의 배수 중 d 자신을 제외한 개수 = floor(n/d) - 1
        int multipleCount = n / d - 1;

        // 그중에서 (k-1)개를 뽑는 조합수를 답에 누적
        answer = (answer + combination(multipleCount, k - 1)) % MOD;
    }

    cout << answer << "\n";

    return 0;
}