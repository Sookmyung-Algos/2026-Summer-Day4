#include <iostream>
#include <vector>

using namespace std;
const int MOD=20100529;

vector<int> memo;

int dp(int n){
    if (n == 1)
        return 1;
    if (n == 2)
        return 3;
    if (memo[n] != -1)
        return memo[n];

    memo[n] = (dp(n - 1)+2*dp(n - 2)) % MOD;

    return memo[n];
}

int main() {
    int N;
    cin >> N;

    memo.assign(N + 1, -1);
    cout << dp(N);
    return 0;
}