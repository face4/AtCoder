// editorialを読んだ
#include<iostream>
#include<vector>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    vector<vector<int>> dp(2, vector<int>(n, 0));
    dp[0][0] = 1;
    dp[1][1] = 1;
    dp[0][1] = s[1]!=s[0] ? 2 : 0;
    for(int i = 2; i < n; i++){
        dp[0][i] = dp[1][i-1]+1;
        if(s[i] != s[i-1])  dp[0][i] = max(dp[0][i], dp[0][i-1]+1);
        dp[1][i] = dp[0][i-2]+1;
        if(i-3 >= 0 && s.substr(i-3,2)!=s.substr(i-1,2))    dp[1][i] = max(dp[1][i], dp[1][i-2]+1);
    }
    cout << max(dp[0][n-1], dp[1][n-1]) << endl;
    return 0;
}