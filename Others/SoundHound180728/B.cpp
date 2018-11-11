#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    int n, k;
    cin >> n >> k;

    int b[n+1];
    for(int i = 1; i <= n; i++)  cin >> b[i];

    ll dp[n+1], ma[n+1];
    dp[0] = ma[0] = 0;

    for(int i = 1; i <= n; i++){
        dp[i] = dp[i-1]+b[i];
        if(i >= k)  dp[i] = max(ma[i-k], dp[i]);
        ma[i] = max(ma[i-1], dp[i]);
    }

    cout << dp[n] << endl;

    return 0;
}