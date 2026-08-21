#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int time, num;
    cin >> time >> num;

    vector<int> path(num + 1);

    for (int i = 0; i < num + 1; i++) {
        cin >> path[i];
    }

    vector<int> way(num + 2, 0);

    for (int i = 1; i < num + 2; i++) {
        way[i] = way[i - 1] + path[i - 1];
    }

    vector<long long> pit(num + 1);

    for (int i = 1; i <= num; i++) {
        cin >> pit[i];
    }

    const long long INF = 1LL << 60;

    vector<long long> dp(num + 2, INF);
    vector<int> parent(num + 2, -1);

    dp[0] = 0;

    for (int i = 1; i <= num + 1; i++) {
        for (int j = 0; j < i; j++) {
            if (way[i] - way[j] <= time) {
                long long repair = 0;

                if (j != 0) {
                    repair = pit[j];
                }

                if (dp[j] + repair < dp[i]) {
                    dp[i] = dp[j] + repair;
                    parent[i] = j;
                }
            }
        }
    }

    vector<int> answer;

    int cur = num + 1;

    while (cur != 0) {
        int prev = parent[cur];

        if (prev >= 1 && prev <= num) {
            answer.push_back(prev);
        }

        cur = prev;
    }

    reverse(answer.begin(), answer.end());

    if (answer.empty()) {
        cout << 0 << '\n';
        return 0;
    }

    cout << dp[num + 1] << '\n';
    cout << answer.size() << '\n';

    for (int x : answer) {
        cout << x << ' ';
    }

    cout << '\n';

    return 0;
}