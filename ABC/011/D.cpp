#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int main(){
    int n, d, x, y;
    cin >> n >> d >> x >> y;
    if(x%d || y%d){
        cout << 0 << endl;
        return 0;
    }
    x /= d, y /= d;
    x = abs(x), y = abs(y);
    // pascal
    vector<vector<double>> dp(n+2, vector<double>(n+2, 0));
    dp[1][1] = 1;
    for(int i = 2; i <= n+1; i++){
        for(int j = 1; j <= i; j++){
            dp[i][j] = (dp[i-1][j]+dp[i-1][j-1])/2;
        }
    }
    double ans = 0;
    // 左右に動く回数を全探索
    for(int i = 0; i <= n; i++){
        double tmp = dp[n+1][i+1];
        if(i%2 == x%2 && i >= x){
            tmp *= dp[i+1][x+(i-x)/2+1];
        }else{
            continue;
        }
        if((n-i)%2 == y%2 && (n-i) >= y){
            tmp *= dp[(n-i)+1][y+(n-i-y)/2+1];
        }else{
            continue;
        }
        ans += tmp;
    }
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}