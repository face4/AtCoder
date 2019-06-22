#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

ll dp[100005][2] = {};

int main(){
    string s;
    cin >> s;
    int n = s.length();
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            dp[i+1][0] += dp[i][0]*2;   dp[i+1][0] %= mod;
            dp[i+1][1] += dp[i][0];     dp[i+1][1] %= mod;
        }else{
            dp[i+1][0] += dp[i][0];     dp[i+1][0] %= mod;
        }

        // 1 - less ならやりたい放題
        dp[i+1][1] += dp[i][1]*3; dp[i+1][1] %= mod;
    }

    cout << (dp[n][0]+dp[n][1])%mod << endl;
    return 0;
}