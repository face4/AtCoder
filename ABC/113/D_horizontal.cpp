#include<iostream>
#include<cstring>
using namespace std;
const int mod = 1000000007;

int main(){
    int h, w, x;
    cin >> h >> w >> x;

    if(w == 1){
        cout << 1 << endl;
        return 0;
    }

    int dp[h+1][w];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;
    for(int i = 1; i <= h; i++){
        for(int j = 0; j < 1<<(w-1); j++){
            int raw[w-1];
            for(int k = 0; k < w-1; k++){
                raw[k] = 1&(j>>k);
            }

            bool judge = true;
            for(int k = 1; k < w-1; k++)  if(raw[k] + raw[k-1] == 2)  judge = false;
            if(!judge)  continue;

            for(int k = 0; k < w-1; k++){
                if(k == 0){
                    if(raw[k] == 1){
                        dp[i][k] += dp[i-1][k+1], dp[i][k] %= mod;
                        dp[i][k+1] += dp[i-1][k], dp[i][k+1] %= mod;
                    }else{
                        dp[i][k] += dp[i-1][k], dp[i][k] %= mod;
                    }
                }else{
                    if(raw[k] == 1){
                        dp[i][k] += dp[i-1][k+1], dp[i][k] %= mod;
                        dp[i][k+1] += dp[i-1][k], dp[i][k+1] %= mod;
                    }else{
                        if(raw[k-1] == 0){
                            dp[i][k] += dp[i-1][k], dp[i][k] %= mod;
                        }
                        if(k == w-2){
                            dp[i][k+1] += dp[i-1][k+1], dp[i][k+1] %= mod;
                        }
                    }
                }
            }
        }
    }

    cout << dp[h][x-1] << endl;

    return 0;
}
