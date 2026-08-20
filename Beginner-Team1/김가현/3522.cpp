#include <iostream>
#include <vector>
using namespace std;

vector<long long> memo;
long long fibo(int n) {
    if (n<=1) return n;

    if (memo[n]!=-1) return memo[n];
    
    memo[n] = (fibo(n-1) + fibo(n-2)) % 1000000007;
    return memo[n];
}

int main() {
    int N;
    cin >> N;

    memo.assign(N+1,-1);
    cout << fibo(N);
}