#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> vp[n];
    int u, v, w;
    for(int i = 1; i < n; i++){
        cin >> u >> v >> w;
        w %= 2;
        u--, v--;
        vp[u].push_back({v,w});
        vp[v].push_back({u,w});
    }
    vector<bool> visit(n, 0);
    queue<pair<int,int>> q;
    for(int i = 0; i < n; i++){
        if(vp[i].size() == 1){
            q.push({i, 0});
            break;
        }
    }
    vector<int> ans(n);
    while(!q.empty()){
        auto p = q.front(); q.pop();
        int i = p.first, col = p.second;
        if(visit[i])    continue;
        visit[i] = true;
        ans[i] = col;
        for(pair<int,int> pp : vp[i]){
            int j = pp.first, ww = pp.second;
            if(visit[j])    continue;
            int ncol = (ww == 1 ? 1-col : col);
            q.push({j, ncol});
        }
    }
    for(int i = 0; i < n; i++)  cout << ans[i] << endl;
    return 0;
}