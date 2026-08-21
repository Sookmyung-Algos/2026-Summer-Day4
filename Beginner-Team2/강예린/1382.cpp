#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, k;
    cin >> T;
    cin >> k;

    vector<int> dp(T + 1, 0);// 금액 j를 만들 수 있는 방법의 수
    dp[0] = 1;

    for (int i = 0; i < k; i++) {
        int p, n; //동전의 금액, 동전의 개수
        cin >> p >> n;

        for (int j = T; j >= 0; j--) {
            if (dp[j] == 0) continue;

            for (int c = 1; c <= n; c++) {
                int next_amount = j + (p * c);

                if (next_amount > T) break;

                dp[next_amount] += dp[j];
            }
        }
    }

    cout << dp[T] << "\n";

    return 0;
}