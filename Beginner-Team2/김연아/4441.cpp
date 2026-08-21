#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    // 빠른 입출력 설정
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k; //nCk

    long long result = 1;

    for (int i = 0; i < k; i++) {
        result *= n - i;
        result /= i + 1;
    }
    cout << result;
    return 0;
}