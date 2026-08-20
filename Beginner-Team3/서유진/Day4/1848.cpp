#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n,m;
    cin >> n >> m;

    queue<int> fix;
    int num;
    
    for (int i=0; i<m; i++) {
        cin >> num;
        fix.push(num);
    }

    fix.push(n+1);
    
    vector<int> fib = {1,1,2};
    int prev, curr;

    int sit=1;
    prev = 0;

    while (!fix.empty()) {
        curr = fix.front();
        fix.pop();

        int indx = curr - prev;

        while (fib.size() <= indx) {
            fib.push_back(fib[fib.size()-1] + fib[fib.size()-2]);
        }

        sit *= fib[indx-1];

        prev = curr;
        
    }
    
    cout << sit;
}