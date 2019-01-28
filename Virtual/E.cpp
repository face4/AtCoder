#include<iostream>
using namespace std;

const int mod = 1e9 + 7;

int main(){
    int dp[301][601] = {};
    for(int i = 0; i < 301; i++)    dp[i][0] = 1;

    int t;
    cin >> t;

    int a[t];
    for(int i = 0; i < t; i++)  cin >> a[i];

    int ans = 0;
    for(int i = 0; i < t; i++){
        for(int j = 300; j >= 0; j--){
            if(dp[i][j] == 0)   continue;
            for(int k = j+1; k <= j+a[i]; k++){
                dp[i][k] = (dp[i][k]+dp[i][j])%mod;
            }
        }
        
        ans += dp[i][1];
        ans %= mod;

        for(int j = 2; j <= 600; j+=2){
            dp[i+1][j/2] = (dp[i+1][j/2]+dp[i][j])%mod;
        }
    }

    ans += dp[t][1];
    ans %= mod;

    cout << ans << endl;

    return 0;
}