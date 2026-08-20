#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int d[1024][1024]; // 최단거리 행렬
vector<int> adj[1024]; // 각 정점의 인접 리스트

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++){
        for (int j = i+1; j <= N; j++){
            cin >> d[i][j];
            d[j][i] = d[i][j];
        }
        d[i][i] = 0;
    }

    for (int i = 1; i <= N; i++){
        for (int j = i+1; j <= N; j++){
            bool edge = true;
            for (int k = 1; k <= N; k++){
                if (k == i || k == j) continue; // 아래 조건 거르기 위함
                if(d[i][k] + d[k][j] == d[i][j]){ // 돌아가는 루트가 직접루트랑 같으면 간선 아님
                    edge = false;
                    break;
                }
            }
            if (edge) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        sort(adj[i].begin(), adj[i].end());
        cout << adj[i].size();

        for (int v : adj[i]) {
            cout << " " << v;
        }
        cout << '\n';        
    }
    return 0;
}