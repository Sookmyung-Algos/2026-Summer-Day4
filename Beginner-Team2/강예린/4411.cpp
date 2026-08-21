#include <iostream>
using namespace std;

int dp[1001][1001]; //dp[i][j] = i명 중 j명을 뽑는 경우의 수

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
        dp[i][i] = 1;
    }

    for (int i = 2; i <= n; i++) { //C(n,k)=C(n−1,k−1)+C(n−1,k)
        for (int j = 1; j < i; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    cout << dp[n][k];

    return 0;
}