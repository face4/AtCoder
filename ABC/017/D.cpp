#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> f(n+1, 0), use(m+1, 0);
    vector<ll> dp(n+1, 0);

    for(int i = 1; i <= n; i++) cin >> f[i];
    dp[0] = 1;
    ll acc = dp[0];
    
    int l = 0;
    for(int r = 1; r <= n; r++){
        use[f[r]]++;
        while(use[f[r]] > 2 || (use[f[r]] == 2 && f[l] != f[r])){
            acc = (acc - dp[l] + mod) % mod;
            use[f[l]]--;
            l++;
        }

        dp[r] = acc;
        acc = (acc + dp[r]) % mod;
    }
    
    cout << dp[n] << endl;

    return 0;
}