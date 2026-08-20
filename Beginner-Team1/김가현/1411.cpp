#include <iostream>
#include <vector>
using namespace std;

vector<long long> memo;
long long tile(int n) {
    if (n==1) return 1;
    else if (n==2) return 3;

    if (memo[n]!=-1) return memo[n];
    
    memo[n] = (tile(n-1) + tile(n-2)*2) % 20100529;
    return memo[n];
}

int main() {
    int N;
    cin >> N;

    memo.assign(N+1,-1);
    cout << tile(N);
}