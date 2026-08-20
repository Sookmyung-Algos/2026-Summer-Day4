#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, w;
    cin >> n;

    vector<int> coin(n);

    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    cin >> w;


    // 밑에서 min 비교 위해 큰 값으로 초기화.
    const int INF = 1000000000;

    vector<int> dp(w + 1, INF);

    // dp[i] = i원을 만드는 데 필요한 최소 동전 개수
    dp[0] = 0;

    for (int i = 1; i <= w; i++) {
        for (int j = 0; j < n; j++) {
            if (coin[j] <= i) {
                dp[i] = min(dp[i],
                    dp[i - coin[j]] + 1);
            }
        }
    }

    if (dp[w] == INF)
        cout << "impossible";
    else
        cout << dp[w];

    return 0;
}