#include<iostream>
using namespace std;

const int D = 1e9+1;

int main(){
    int n, W;
    cin >> n >> W;

    int dp[100001];
    for(int i = 0; i < 100001; i++) dp[i] = D;
    dp[0] = 0;

    int w, v;
    for(int i = 0; i < n; i++){
        cin >> w >> v;
        for(int j = 100001; j >= v; j--){
            if(dp[j-v] == D)    continue;
            dp[j] = min(dp[j], dp[j-v]+w);
        }
    }

    int ans = 0;
    for(int i = 0; i < 100001; i++) if(dp[i] <= W)  ans = max(ans, i);

    cout << ans << endl;

    return 0;
}