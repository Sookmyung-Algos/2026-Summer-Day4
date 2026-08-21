/*#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 탑다운보다 바텀업으로 하는 게 더 좋다.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> dp(n + 1);

    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i <= n; i++) {
        // 마지막에만 계산하는 게 아니라 더할 때마다 매번 나머지를 구해야 함
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
    }

    cout << dp[n];

    return 0;
}*/