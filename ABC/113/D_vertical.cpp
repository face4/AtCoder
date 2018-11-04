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

            for(int k = 0; k < w; k++){
                int nk = k;
                if(k > 0 && raw[k-1] == 1)  nk--;
                if(k < w-1 && raw[k] == 1)   nk++;
                dp[i][nk] += dp[i-1][k], dp[i][nk] %= mod;
            }
        }
    }

for(int i = 0; i <= h; i++){
    for(int j = 0; j < w; j++){
        cout << dp[i][j] << " ";
    }
    cout << endl;
}

    cout << dp[h][x-1] << endl;

    return 0;
}