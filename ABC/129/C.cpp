#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int main(){
    int n, m;
    cin >> n >> m;
    vector<bool> ok(n+5, true);
    while(m-- > 0){
        int x;
        cin >> x;
        ok[x] = false;
    }
    vector<ll> dp(n+5, 0);
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        if(ok[i+1]) dp[i+1] = (dp[i+1]+dp[i])%mod;
        if(ok[i+2]) dp[i+2] = (dp[i+2]+dp[i])%mod;
    }
    cout << dp[n] << endl;
    return 0;
}