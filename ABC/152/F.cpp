#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main(){
    int n;
    cin >> n;
    vector<pii> v[n];
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        v[a].push_back({b, i});
        v[b].push_back({a, i});
    }
    
    ll num[n][n];
    for(int i = 0; i < n; i++){
        vector<bool> vis(n, 0);
        num[i][i] = 0;
        queue<int> q;
        q.push(i);
        vis[i] = true;
        while(!q.empty()){
            int x = q.front();  q.pop();
            for(pii p : v[x]){
                if(vis[p.first])    continue;
                vis[p.first] = true;
                num[i][p.first] = num[i][x] + (1ll<<p.second);
                q.push(p.first);
            }
        }
    }
    int m;
    cin >> m;
    vector<pii> vp(m);
    for(int i = 0; i < m; i++){
        cin >> vp[i].first >> vp[i].second;
        vp[i].first--, vp[i].second--;
    }
    ll ans = 1ll<<(n-1);
    for(int i = 1; i < 1<<m; i++){
        int popcnt = 0;
        ll allwhite = 0;
        for(int j = 0; j < m; j++){
            if((i>>j&1) == 0)    continue;
            popcnt++;
            allwhite |= num[vp[j].first][vp[j].second];
        }
        ll ppcnt = 0;
        for(int j = 0; j < n; j++)  ppcnt += (allwhite>>j)&1;
        ans += (popcnt%2 == 0 ? 1 : -1)*(1ll<<(n-1-ppcnt));
    }
    cout << ans << endl;
    return 0;
}