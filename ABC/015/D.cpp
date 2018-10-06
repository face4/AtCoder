#include<iostream>
using namespace std;

int dp[51][10001] = {};

int main(){
    int w, n, K;
    cin >> w >> n >> K;

    int a[n], b[n];
    for(int i = 0; i < n; i++)  cin >> a[i] >> b[i];

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int k = K; k >= 1; k--){
            for(int j = w; j >= a[i]; j--){
                dp[k][j] = max(dp[k][j], dp[k-1][j-a[i]]+b[i]);
                ans = max(ans, dp[k][j]);
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}