#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> s(n), t(m);
    for(int i = 0; i < n; i++)  cin >> s[i];
    for(int i = 0; i < m; i++)  cin >> t[i];
    vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));
    for(int i = 0; i <= n; i++) dp[i][0] = 1;
    for(int j = 0; j <= m; j++) dp[0][j] = 1;
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = (dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+mod)%mod;
            if(s[i-1] == t[j-1]){
                dp[i][j] += dp[i-1][j-1];
                dp[i][j] %= mod;
            }else{
                // do nothing
            }
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}