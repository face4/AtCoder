// DEGwerさんの数え上げpdfを読んで
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define inRange(x,a,b) (a <= x && x < b)
typedef long long ll;
const int mod = 1000000007;

int main(){
    int n;
    string s;
    cin >> n >> s;
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= n; j++){
            if(dp[i][j] == 0)   continue;
            int del = max(0, j-1), add = j+1;
            dp[i+1][del] += dp[i][j];
            dp[i+1][del] %= mod;
            dp[i+1][add] += 2*dp[i][j];
            dp[i+1][add] %= mod;
        }
    }
    int ans = dp[n][s.length()];
    for(int i = 0; i < s.length(); i++){
        if(ans%2)   ans += mod;
        ans /= 2;
    }
    cout << ans << endl;
    return 0;
}