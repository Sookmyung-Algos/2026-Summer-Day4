#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> fibo(n);
	int sum = 0;

	fibo[0] = 1;
	fibo[1] = 3;

	int i = 2;
	while (1) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		if (fibo[i] > n)break;
		if (fibo[i] % 2 == 0) {
			sum += fibo[i];
		}
		i++;
	}

	cout << sum;
	return 0;

}