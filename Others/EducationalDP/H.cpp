#include<iostream>
using namespace std;
const int mod = 1e9+7;

int main(){
    int h, w;
    cin >> h >> w;

    char mat[h][w];
    static int dp[1000][1000] = {};

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
        }
    }

    dp[0][0] = 1;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(mat[i][j] == '#')    continue;
            if(i)   dp[i][j] += dp[i-1][j];
            if(j)   dp[i][j] += dp[i][j-1];
            dp[i][j] %= mod;
        }
    }

    cout << dp[h-1][w-1] << endl;

    return 0;
}