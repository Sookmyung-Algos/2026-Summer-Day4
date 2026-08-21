#include <iostream>
using namespace std;

int N, M, x;
bool A[41];
int dp[41];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; i++){
        cin >> x;
        A[x] = true;
    }

    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= N; i++){
        if (!A[i] && !A[i-1]){
            dp[i] = dp[i-1] + dp[i-2];
        }
        else dp[i] = dp[i-1];
    }

    cout << dp[N] << '\n';
    return 0;
}