#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int D, N; // 최대 거리, 정비소 개수
int dist[102]; // 인접 구간 거리
int cost[102]; // 각 정비소의 정비 시간

int dp[102]; // 최소 총 정비시간
int pos[102]; // 누적 거리
int pre[102]; // 최적 경로 상의 직전 정비소 번호

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> D >> N;
    for (int i = 1; i <= N+1; i++){
        cin >> dist[i];
    }
    
    for (int i = 1; i <= N; i++){
        cin >> cost[i];
    }

    dp[0] = 0;
    pos[0] = 0;
    cost[N+1] = 0; // 도착 지점은 정비비용 x

    for (int i = 1; i <= N+1; i++) 
        pos[i] = pos[i-1] + dist[i];


    if (pos[N+1] <= D){ // 한번에 도착지점 가는 경우
        cout << 0 << '\n';    
        return 0;
    }
        
    int best;

    for (int i = 1; i <= N + 1; i++){ // 첫 번째 정비소 ~ 도착점
        best = -1;
        for (int j = 0; j <= i-1; j++){ // 이전 위치 탐색
            if (pos[i] - pos[j] <= D){ 
                if (best == -1 || dp[j] < dp[best]) // dp[j]가 가장 작은 곳 선택
                    best = j;
            }
        }
        dp[i] = dp[best] + cost[i];
        pre[i] = best;
    }

    cout << dp[N+1] << '\n';

    // 경로 추적
    vector<int> route;
    int cur = pre[N+1]; // 도착점의 이전 위치

    while (cur != 0){
        route.push_back(cur);
        cur = pre[cur];
    }
    
    reverse(route.begin(), route.end());

    cout << route.size() << '\n'; 
    for (int x : route)
        cout << x << ' ';

    return 0;
}