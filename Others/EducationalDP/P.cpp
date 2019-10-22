// 自力AC
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;

const int mod = 1000000007;

vector<int> v[100000];
ll dp[2][100000] = {};
bool vis[2][100000] = {};

int dfs(int p, int x, int c){
    if(dp[c][x])   return dp[c][x];
    dp[c][x] = 1;
    for(int child : v[x]){
        if(child == p)   continue;
        ll tmp = dfs(x, child, 0);
        if(c == 0){
            tmp += dfs(x, child, 1);
            tmp %= mod;
        }
        dp[c][x] *= tmp;
        dp[c][x] %= mod;            
    }
    return dp[c][x];
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cout << (dfs(-1,0,0)+dfs(-1,0,1))%mod << endl;
    return 0;
}
