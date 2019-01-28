#include<iostream>
#include<iomanip>
using namespace std;

double dp[301][301][301] = {};
int n;

double dfs(int i, int j, int k){
    if(dp[i][j][k] > 0) return dp[i][j][k];
    if(i+j+k == 0)  return 0;

    double ret = 1.0;
    if(i)   ret += (double)i / n * dfs(i-1, j, k);
    if(j)   ret += (double)j / n * dfs(i+1, j-1, k);
    if(k)   ret += (double)k / n * dfs(i, j+1, k-1);

    ret *= (double)n / (i+j+k);

    return dp[i][j][k] = ret;
}

int main(){
    cin >> n;

    int cnt[3] = {}, a;
    for(int i = 0; i < n; i++){
        cin >> a;
        cnt[--a]++;
    }

    cout << fixed << setprecision(12) << dfs(cnt[0], cnt[1], cnt[2]) << endl;

    return 0;
}