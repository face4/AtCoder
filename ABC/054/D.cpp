#include<iostream>
using namespace std;

const int INF = 1<<25;
int dp[401][401] = {};

int main(){
    for(int i = 0; i < 401; i++){
        for(int j = 0; j < 401; j++){
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;

    int n, ma, mb, a, b, c;
    cin >> n >> ma >> mb;

    while(n-- > 0){
        cin >> a >> b >> c;
        for(int i = 400-a; i >= 0; i--){
            for(int j = 400-b; j >= 0; j--){
                if(dp[i][j] != INF) dp[i+a][j+b] = min(dp[i+a][j+b], dp[i][j]+c);
            }
        }
    }

    int ans = INF;
    for(int i = 1; i <= 400; i++){
        for(int j = 1; j <= 400; j++){
            if(i*mb == j*ma)    ans = min(ans, dp[i][j]);
        }
    }

    if(ans == INF)  ans = -1;

    cout << ans << endl;
    
    return 0;
}