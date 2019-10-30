#include<iostream>
using namespace std;

const int mod = 1000000007;
int dp[10001][2][101] = {};

int main(){
    string s;
    int d;
    cin >> s >> d;
    int n = s.length();
    dp[0][0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k <= d; k++){
                for(int l = 0; l <= 9; l++){
                    if(j == 0 && l > s[i]-'0')  continue;
                    int ni = i+1;
                    int nj = j|(l<s[i]-'0');
                    int nk = (k+l)%d;
                    dp[ni][nj][nk] += dp[i][j][k];
                    dp[ni][nj][nk] %= mod;
                }
            }
        }
    }
    cout << (dp[n][0][0]+dp[n][1][0]-1+mod)%mod << endl;
    return 0;
}