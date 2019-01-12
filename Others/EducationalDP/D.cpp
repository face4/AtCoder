#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;

int main(){
    int n, W;
    cin >> n >> W;

    ll dp[W+1];
    memset(dp, 0, sizeof(dp));

    ll w, v;
    for(int i = 0; i < n; i++){
        cin >> w >> v;
        for(int j = W; j >= w; j--){
            dp[j] = max(dp[j], dp[j-w]+v);
        }
    }

    cout << dp[W] << endl;

    return 0;
}