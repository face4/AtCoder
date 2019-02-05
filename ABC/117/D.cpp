#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

typedef long long ll;

int main(){
    int n;
    ll k;
    cin >> n >> k;

    vector<ll> a(n);
    for(int i = 0; i < n; i++)  cin >> a[i];

    if(k == 0){
        cout << accumulate(a.begin(), a.end(), 0ll) << endl;
        return 0;
    }

    // 0の数
    vector<int> cnt(50, 0);
    for(int i = 0; i < 50; i++){
        for(int j = 0; j < n; j++){
            if(((a[j]>>i)&1)==0)    cnt[i]++; 
        }
    }

    vector<vector<ll>> dp(50, vector<ll>(2, 0ll));

    ll t = 48;
    while( ((k>>t)&1) == 0 ){
        // kの力が及ばない高bit域ではkは0を取るしかない
        dp[t][0] = dp[t][1] = (1ll<<t) * (n-cnt[t]);
        dp[t][0] += dp[t+1][0];
        dp[t][1] += dp[t+1][1];
        t--;
    } 

    // 0 -> even, 1 -> less
    dp[t][0] = (1ll<<t) * cnt[t] + dp[t+1][0];
    dp[t][1] = (1ll<<t) * (n-cnt[t]) + dp[t+1][1];

    for(t--; t >= 0; t--){
        ll zero = (1ll<<t) * (n-cnt[t]);
        ll one = (1ll<<t) * cnt[t];

        if((k>>t)&1){
            dp[t][0] = dp[t+1][0] + one;
            dp[t][1] = max(dp[t+1][1] + max(zero, one), dp[t+1][0]+zero);
        }else{
            dp[t][0] = dp[t+1][0] + zero;
            dp[t][1] = dp[t+1][1] + max(one, zero);
        }
    }

    cout << max(dp[0][0], dp[0][1]) << endl;

    return 0;
}