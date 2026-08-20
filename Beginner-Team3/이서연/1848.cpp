#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int M;
    cin >> M;

    int dp[41];

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int answer = 1;
    int previous = 0;

    for (int i = 0; i < M; i++) {
        int vip;
        cin >> vip;

        int length = vip - previous - 1;

        answer *= dp[length];

        previous = vip;
    }

    answer *= dp[N - previous];

    cout << answer;

    return 0;
}