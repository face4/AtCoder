#include<iostream>
using namespace std;
typedef long long ll;

ll dp[3002][3002] = {};
ll a[3001];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)  cin >> a[i];
    for(int i = n; i >= 1; i--){
        for(int j = i; j <= n; j++){
            int taken = n-i-j-1;
            if(taken%2){
                // Jiro
                dp[i][j] = min(dp[i+1][j]-a[i], dp[i][j-1]-a[j]);
            }else{
                // Taro
                dp[i][j] = max(dp[i+1][j]+a[i], dp[i][j-1]+a[j]);
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}