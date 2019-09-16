#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;

// ???
int main(){
    int n;
    string s;
    cin >> n >> s;

    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i = 1; i < n; i++){
        if(s[0] == s[i])    dp[0][i] = 1;
    }

    for(int i = 1; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(s[i] != s[j])    continue;
            if(i < j-dp[i-1][j-1])  dp[i][j] = dp[i-1][j-1]+1;
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}