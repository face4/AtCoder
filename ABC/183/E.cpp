#include<iostream>
#include<vector>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    char mat[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
        }
    }
    vector<vector<int>> dp(h, vector<int>(w, 0)), diag(h, vector<int>(w, 0)), up(h, vector<int>(w, 0)), rig(h, vector<int>(w, 0));
    dp[0][0] = diag[0][0] = up[0][0] = rig[0][0] = 1;
    const int mod = 1000000007;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(mat[i][j] == '#')  continue;
            if(i > 0)   (dp[i][j] += up[i-1][j]) %= mod;
            if(j > 0)   (dp[i][j] += rig[i][j-1]) %= mod;
            if(i > 0 && j > 0)  (dp[i][j] += diag[i-1][j-1]) %= mod;
            (up[i][j] = (i>0?up[i-1][j]:0)+dp[i][j]) %= mod;
            (rig[i][j] = (j>0?rig[i][j-1]:0)+dp[i][j]) %= mod;
            (diag[i][j] = (i>0&&j>0?diag[i-1][j-1]:0)+dp[i][j]) %= mod;
        }
    }
    cout << dp.back().back() << endl;
    return 0;
}