#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    ll x[n], y[n], z[n];
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i] >> z[i];
    }
    auto f = [&](int i, int j)->ll{
        return abs(x[i]-x[j])+abs(y[i]-y[j])+max(0ll,z[j]-z[i]);
    };
    vector<vector<ll>> dp(n-1, vector<ll>(1<<(n-1), 1ll<<62));
    for(int i = 0; i < n-1; i++){
        dp[i][1<<i] = f(0, i+1);
    }
    for(int s = 0; s < 1<<(n-1); s++){
        for(int j = 0; j < n-1; j++){
            if((s>>j&1) == 0)   continue;
            if(dp[j][s] == 1ll<<62) continue;
            for(int k = 0; k < n-1; k++){
                if(s>>k&1)  continue;
                dp[k][s|(1<<k)] = min(dp[k][s|(1<<k)], dp[j][s]+f(j+1,k+1));
            }
        }
    }
    ll ans = 1ll<<62;
    for(int j = 0; j < n-1; j++){
        ans = min(ans, dp[j][(1<<(n-1))-1]+f(j+1, 0));
    }
    cout << ans << endl;
    return 0;
}