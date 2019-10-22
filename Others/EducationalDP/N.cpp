// 自力AC
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];
    vector<vector<ll>> dp(n, vector<ll>(n, 1ll<<60));
    for(int i = 0; i < n; i++)  dp[i][i] = 0;
    for(int i = 1; i < n; i++)  a[i] += a[i-1];
    for(int wid = 2; wid <= n; wid++){
        for(int i = 0; i+wid-1 < n; i++){
            for(int j = i; j < i+wid-1; j++){
                dp[i][i+wid-1] = min(dp[i][i+wid-1], dp[i][j]+dp[j+1][i+wid-1]);
            }
            dp[i][i+wid-1] += a[i+wid-1] - (i==0 ? 0 : a[i-1]);
        }
    }
    cout << dp[0][n-1] << endl;
    return 0;
}
