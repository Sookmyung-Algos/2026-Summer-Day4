#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long maxDist;
    cin >> maxDist;

    int N;
    cin >> N;

    vector<long long> dist(N + 2, 0);
    vector<long long> repair(N + 2, 0);

    for (int i = 1; i <= N + 1; i++) {
        long long d;
        cin >> d;

        dist[i] = dist[i - 1] + d;
    }

    for (int i = 1; i <= N; i++) {
        cin >> repair[i];
    }

    const long long INF = 1e18;

    vector<long long> dp(N + 2, INF);
    vector<int> parent(N + 2, -1);

    dp[0] = 0;

    for (int i = 1; i <= N + 1; i++) {

        for (int j = i - 1; j >= 0; j--) {

            if (dist[i] - dist[j] > maxDist) {
                break;
            }

            if (dp[i] > dp[j] + repair[j]) {
                dp[i] = dp[j] + repair[j];
                parent[i] = j;
            }
        }
    }

    cout << dp[N + 1] << '\n';

    vector<int> path;

    int cur = parent[N + 1];

    while (cur != 0) {
        path.push_back(cur);
        cur = parent[cur];
    }

    reverse(path.begin(), path.end());

    if (path.empty()) {
        return 0;
    }

    cout << path.size() << '\n';

    for (int x : path) {
        cout << x << " ";
    }

    return 0;
}