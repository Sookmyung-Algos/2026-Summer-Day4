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

    int n;
    cin >> n;

    vector<long long> fibo(n);
    long long total = 0;

    fibo[0] = 1;
    fibo[1] = 3;

    int i = 1;
    while (fibo[i++] <= n) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        if (fibo[i] % 2 == 0 && fibo[i] <= n) total += fibo[i];
    }

    /*확인용
    for (int i = 0; i < fibo.size(); i++) {
        cout << fibo[i] << ' ';
    }*/

    cout << total << endl;

    return 0;
}