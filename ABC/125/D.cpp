#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)  cin >> a[i];
    vector<vector<ll>> dp(n, vector<ll>(2, 0));
    dp[1][1] = a[0]+a[1];
    dp[1][0] = -a[0]-a[1];
    for(int i = 1; i < n-1; i++){
        dp[i+1][0] = max(dp[i][0]+2*a[i]-a[i+1], dp[i][1]-2*a[i]-a[i+1]);
        dp[i+1][1] = max(dp[i][0]+a[i+1], dp[i][1]+a[i+1]);
    }
    cout << max(dp[n-1][0], dp[n-1][1]) << endl;
    return 0;
}