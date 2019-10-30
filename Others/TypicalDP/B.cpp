// 終了条件をl==a&&r==bにしているので遅いかもしれない
#include<iostream>
using namespace std;

int a, b;
int dp[1001][1001] = {};

int dfs(int l, int r, int* x, int* y, bool turn){
    if(dp[l][r])    return dp[l][r];
    if(l == a && r == b)    return dp[l][r] = 0;
    if(turn){
        if(l < a)   dp[l][r] = max(dp[l][r], x[l]+dfs(l+1, r, x, y, !turn));
        if(r < b)   dp[l][r] = max(dp[l][r], y[r]+dfs(l, r+1, x, y, !turn));
    }else{
        dp[l][r] = 1<<30;
        if(l < a)   dp[l][r] = min(dp[l][r], dfs(l+1, r, x, y, !turn));
        if(r < b)   dp[l][r] = min(dp[l][r], dfs(l, r+1, x, y, !turn));
    }
    return dp[l][r];
}

int main(){
    cin >> a >> b;
    int x[a], y[b];
    for(int i = 0; i < a; i++)  cin >> x[i];
    for(int i = 0; i < b; i++)  cin >> y[i];
    cout << dfs(0, 0, x, y, true) << endl;
    return 0;
}
