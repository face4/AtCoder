// 自力でAC出来た
// 累積和+メモリ削減
#include<iostream>
#include<vector>
using namespace std;

const int mod = 1000000007;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    vector<int> dp(k+1, 0);
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        vector<int> ndp(k+1, 0);
        for(int j = 0; j <= k; j++){
            ndp[j] = (ndp[j] + dp[j])%mod;
            if(j+v[i]+1 <= k) ndp[j+v[i]+1] = (ndp[j+v[i]+1]-dp[j]+mod)%mod;
        }
        for(int j = 1; j <= k; j++) ndp[j] = (ndp[j]+ndp[j-1])%mod;
        dp = ndp;
    }
    cout << dp[k] << endl;
    return 0;
}
