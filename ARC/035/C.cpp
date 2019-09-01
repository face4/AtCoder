#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;
    ll dp[n][n];
    for(int i = 0; i < n; i++)  for(int j = 0; j < n; j++)  dp[i][j] = (i!=j ? 1ll<<60 : 0);
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        dp[a][b] = min(dp[a][b], (ll)c);
        dp[b][a] = min(dp[b][a], (ll)c);
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            if(dp[i][k] == 1ll<<60)   continue;
            for(int j = 0; j < n; j++){
                if(dp[k][j] == 1ll<<60)   continue;
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++)  for(int j = i+1; j < n; j++)  ans += dp[i][j];
    int q;
    cin >> q;
    while(q-- > 0){
        int x, y, z;
        cin >> x >> y >> z;
        x--, y--;
        if(dp[x][y] < z){
            cout << ans << endl;
            continue;
        }
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                ll to = min(dp[i][x]+z+dp[y][j], dp[i][y]+z+dp[x][j]);
                if(to < dp[i][j]){
                    ans -= dp[i][j]-to;
                    dp[i][j] = dp[j][i] = to;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}