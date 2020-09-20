// ???
#include<iostream>
#include<vector>
#include<map>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    int k = n/2;
    map<int,ll> dp[n];
    // dp[i][x] := use v[i], count x, max value
    dp[0][0] = 0;
    dp[0][1] = v[0];
    dp[1][0] = 0;
    dp[1][1] = max(v[0], v[1]);
    for(int i = 2; i < n; i++){
        int residual = (n-i-1)/2;
        for(int now = max(k-residual, 1); now <= k; now++){
            if(dp[i-2].count(now-1) == 0)   break;
            dp[i][now] = dp[i].count(now) ? max(dp[i][now], dp[i-2][now-1]+v[i]) : dp[i-2][now-1]+v[i];
            if(dp[i-1].count(now))  dp[i][now] = max(dp[i][now], dp[i-1][now]);
        }
        // for(auto p : dp[i]) if(dp[i-1].count(p.first))  dp[i][p.first] = max(p.second, dp[i-1][p.first]);
    }
    ll ma = -(1ll<<60);
    for(int i = 0; i < n; i++)  if(dp[i].count(k))   ma = max(ma, dp[i][k]);
    cout << ma << endl;
    return 0;
}