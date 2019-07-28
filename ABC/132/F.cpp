#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> to, val;
    int r = 1;
    while(r <= n){
        int tmp = n/r;
        int reach = n/tmp;
        to.push_back(reach);
        val.push_back(tmp);
        r = reach+1;
    }

    int siz = to.size(); // O(sqrt(N)) ?

    vector<ll> cnt(siz, 1);
    for(int i = 1; i < siz; i++)    cnt[i] = to[i]-to[i-1];

    auto f = [&](int x)->int{
        return upper_bound(to.begin(),to.end(),x)-to.begin();
    };

    // memo (needless)
    vector<int> memo(siz);
    for(int i = 0; i < siz; i++)    memo[i] = f(val[i]);

    // O(sqrt(N) * K) ?
    vector<vector<ll>> dp(k, vector<ll>(siz+1, 0));
    for(int i = 0; i < siz; i++)    dp[0][i] = cnt[i];
    for(int i = 0; i+1 < k; i++){
        for(int j = 0; j < siz; j++){
            dp[i+1][0] = (dp[i+1][0] + dp[i][j]) % mod;
            dp[i+1][memo[j]] = (dp[i+1][memo[j]] - dp[i][j] + mod) % mod;
        }
        for(int j = 1; j < siz; j++){
            dp[i+1][j] += dp[i+1][j-1];
            if(dp[i+1][j] < 0)    dp[i+1][j] += mod;
            dp[i+1][j] %= mod;
        }
        for(int j = 0; j < siz; j++){
            dp[i+1][j] *= cnt[j];
            dp[i+1][j] %= mod;
        }
    }

    ll ans = 0;
    for(int i = 0; i < siz; i++)    ans += dp[k-1][i], ans %= mod;
    cout << ans << endl;

    return 0;
}
