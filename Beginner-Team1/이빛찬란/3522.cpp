#include <iostream>
using namespace std;
long long dp[100001];
const long long MOD = 1000000007;

int fibo(int n) {
	
	if (n == 1 || n == 2) {
		return 1;
	}
	if(dp[n]!=-1) {
		return dp[n];
	}
	return dp[n]=(fibo(n - 1) + fibo(n - 2))%MOD;
}

int main() {
	int n;
	
	cin >> n;

	for (int i = 0; i <= 100000; i++) {
		dp[i] = -1;
	}
	cout << fibo(n) % MOD;
}