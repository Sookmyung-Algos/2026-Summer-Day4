#include <iostream>
#include <vector>

using namespace std;

struct Coin {
    int price;
    int count;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, k;
    cin >> T >> k;

    vector<Coin> coins(k);
    for (int i = 0; i < k; i++) {
        cin >> coins[i].price >> coins[i].count;
    }

    // dp[j]: j원을 만드는 경우의 수
    vector<int> dp(T + 1, 0);
    dp[0] = 1; // 0원을 만드는 방법은 아무 동전도 쓰지 않는 1가지

    for (int i = 0; i < k; i++) {
        int p = coins[i].price;
        int count = coins[i].count;

        // 역순으로 순회하여 같은 종류 동전의 중복 반영 방지
        for (int j = T; j >= 1; j--) {
            for (int c = 1; c <= count; c++) {
                if (j - p * c >= 0) {
                    dp[j] += dp[j - p * c];
                }
                else {
                    break; // 금액을 초과하면 더 이상 볼 필요 없음
                }
            }
        }
    }

    cout << dp[T] << "\n";

    return 0;
}