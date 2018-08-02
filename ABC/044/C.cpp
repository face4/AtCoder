#include<iostream>
using namespace std;

long long dp[51][6000] = {};

int main(){
    int n, a;
    cin >> n >> a;

    int x[n];
    for(int i = 0; i < n; i++){
        cin >> x[i];
        x[i] -= a;
    }  

    dp[0][3000] = 1;

    for(int i = 1; i <= n; i++){
        int now = x[i-1];
        for(int j = 0; j < 6000; j++){
            if(dp[i-1][j] == 0) continue;
            int next = j+now;
            if(0 <= next && next < 6000)    dp[i][next] += dp[i-1][j];
            dp[i][j] += dp[i-1][j];        
        }
    }

    cout << dp[n][3000]-1 << endl;

    return 0;
}