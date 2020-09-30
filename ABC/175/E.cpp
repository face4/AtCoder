#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
ll dp[4][3000][3000] = {};

int main(){
    int r, c, k;
    cin >> r >> c >> k;
    vector<vector<int>> v(r, vector<int>(c, 0));
    while(k--){
        int i, j, val;
        cin >> i >> j >> val;
        v[--i][--j] = val;
    }
    dp[1][0][0] = v[0][0];
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            for(int num = 0; num < 4; num++){
                if(i+1 < r){
                    dp[0][i+1][j] = max(dp[0][i+1][j], dp[num][i][j]);
                    dp[1][i+1][j] = max(dp[1][i+1][j], dp[num][i][j]+v[i+1][j]);
                }
                if(j+1 < c){
                    dp[num][i][j+1] = max(dp[num][i][j+1], dp[num][i][j]);
                    if(num < 3) dp[num+1][i][j+1] = max(dp[num+1][i][j+1], dp[num][i][j]+v[i][j+1]);
                }
            }
        }
    }
    ll ans = 0;
    for(int num = 0; num < 4; num++)    ans = max(ans, dp[num][r-1][c-1]);
    cout << ans << endl;
    return 0;
}