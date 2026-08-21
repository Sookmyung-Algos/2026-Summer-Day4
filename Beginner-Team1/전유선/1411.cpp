#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> dp(n + 1);

    dp[1] = 1;
    dp[2] = 3;

    // 사례 놓고 점화식 생각해보면 이렇게 나온다.
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + 2*dp[i - 2]) % 20100529;
    }

    cout << dp[n];

    return 0;
}