#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int coin[10];
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	int w;
	cin >> w;

	const int INF = 1e9;
	int dp[64001];
	dp[0] = 0;
	for (int i = 1; i <= w; i++) {
		dp[i] = INF;
	}

	for (int i = 1; i <= w; i++) {
		for (int j = 0; j < n; j++) {
			if (coin[j] <= i && dp[i - coin[j]] != INF) {
				if (dp[i - coin[j]] + 1 < dp[i]) {
					dp[i] = dp[i - coin[j]] + 1;
				}
			}
		}
	}

	if (dp[w] == INF) {
		cout << "impossible";
	}
	else {
		cout << dp[w];
	}

	return 0;
}
