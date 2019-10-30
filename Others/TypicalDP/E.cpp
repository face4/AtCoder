#include<iostream>
using namespace std;
const int mod = 1e9+7;

int dp[10001][2][100] = {};

int main(){
    int d;
    string s;
    cin >> d >> s;
    int n = s.length();
    dp[0][0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2; j++){
            int lim = j ? 9 : s[i]-'0';
            for(int k = 0; k < d; k++){
                for(int l = lim; l >= 0; l--){
                    dp[i+1][j||(l < lim)][(k+l)%d] += dp[i][j][k];
                    dp[i+1][j||(l < lim)][(k+l)%d] %= mod;
                }
            }
        }
    }
    cout << (dp[n][0][0] + dp[n][1][0] - 1 + mod)%mod << endl;
    return 0;
}
