#include <iostream>
using namespace std;

long long num[100001];

int main(){
    int N;
    cin>>N;

    num[1] =1;
    num[2] =1;

    for (int i = 3; i <= N; i++){
        num[i] = (num[i - 1]+num[i - 2])%1000000007;
    }

    cout<<num[N];
    return 0;
}