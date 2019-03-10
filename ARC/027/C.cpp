#include<iostream>
#include<vector>
using namespace std;

int dp[601][301] = {};

int main(){
    int x, y, n, t, h;
    cin >> x >> y >> n;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        cin >> t >> h;
        for(int j = x+y-t; j >= 0; j--){
            for(int k = min(i, x); k >= 1; k--){
                dp[j+t][k] = max(dp[j+t][k], dp[j][k-1]+h);
                ans = max(ans, dp[j+t][k]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}