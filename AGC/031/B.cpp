#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

vector<int> pos[200001], cur(200001, 0);

int main(){
    int n;
    cin >> n;

    vector<int> c(n);
    for(int i = 0; i < n; i++)  cin >> c[i];

    vector<ll> dp(n, 0);
    dp[0] = 1;
    
    for(int i = 0; i < n; i++)  pos[c[i]].push_back(i);

    for(int i = 0; i < n-1; i++){
        // for(int j = cur[c[i]]+1; j < pos[c[i]].size(); j++){
        //     if(pos[c[i]][j]-pos[c[i]][j-1] == 1)    continue;
        //     dp[pos[c[i]][j]] += dp[i];
        //     dp[pos[c[i]][j]] %= mod;
        // }
        int j = cur[c[i]]+1;
        if(j < pos[c[i]].size() && pos[c[i]][j]-pos[c[i]][j-1] != 1){
            dp[pos[c[i]][j]] += dp[i];
            dp[pos[c[i]][j]] %= mod;
        }
        cur[c[i]]++;
        dp[i+1] += dp[i];
        dp[i+1] %= mod;
    }

    cout << dp[n-1] << endl;

    return 0;
}