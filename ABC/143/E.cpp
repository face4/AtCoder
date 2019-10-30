#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef long long ll;

int main(){
    int n, m, l;
    cin >> n >> m >> l;
    ll mat[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            mat[i][j] = 1ll<<60;
        }
    }
    while(m-- > 0){
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        mat[a][b] = mat[b][a] = c;
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][k] == 1ll<<60 || mat[k][j] == 1ll<<60)  continue;
                mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);
            }
        }
    }
    vector<int> path[n];
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(mat[i][j] > l)   continue;
            path[i].push_back(j);
            path[j].push_back(i);
        }
    }
    int q;
    cin >> q;
    while(q-- > 0){
        int s, t;
        cin >> s >> t;
        s--, t--;
        vector<int> dp(n, 1<<30);
        queue<int> q;
        q.push(s);
        dp[s] = -1;
        while(!q.empty()){
            int x = q.front();  q.pop();
            for(int next : path[x]){
                if(dp[next] > dp[x]+1){
                    dp[next] = dp[x]+1;
                    if(next == t){
                        break;
                    }
                    q.push(next);
                }
            }
            if(dp[t] != 1<<30)  break;
        }
        cout << (dp[t] == 1<<30 ? -1 : dp[t]) << endl;
    }
    return 0;
}