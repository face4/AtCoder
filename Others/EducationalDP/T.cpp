// 解説を読んだ　難しい
#include<iostream>
using namespace std;

int dp[3000][3000] = {};
const int mod = 1e9+7;

int main(){
    int n;
    string s;
    cin >> n >> s;
    for(int i = 0; i < n; i++)  dp[0][i] = 1;
    auto f = [=](int i, int j, int k)->int{
        return (dp[i][k] - (j==0 ? 0 : dp[i][j-1]) + mod)%mod;
    };
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++)  dp[i-1][j] = (dp[i-1][j]+dp[i-1][j-1])%mod;
        for(int j = 0; j <= n-1-i; j++){
            if(s[i-1] == '<') dp[i][j] = f(i-1, 0, j);
            if(s[i-1] == '>') dp[i][j] = f(i-1, j+1, n-1);
        }
    }
    cout << dp[n-1][0] << endl;
    return 0;
}