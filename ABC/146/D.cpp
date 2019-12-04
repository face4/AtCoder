#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;

typedef pair<int,int> pii;

int main(){
    int n;
    cin >> n;
    vector<int> v[n], deg(n, 0);
    vector<pii> vp;
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        v[a].push_back(b);
        v[b].push_back(a);
        vp.push_back({a,b});
        deg[a]++, deg[b]++;
    }
    int k = *max_element(deg.begin(), deg.end());
    cout << k << endl;
    int f;
    for(int i = 0; i < n; i++)  if(deg[i] == k) f = i;
    map<pii,int> col;
    queue<pii> q;
    q.push({0,f});
    vector<bool> vis(n, 0);
    vis[f] = true;
    while(!q.empty()){
        auto x = q.front();  q.pop();
        int now = 1;
        for(int child : v[x.second]){
            if(vis[child])  continue;
            vis[child] = true;
            if(now == x.first)  now++;
            col[{min(x.second,child),max(x.second,child)}] = now;
            q.push({now++, child});
        }
    }
    for(pii p : vp) cout << col[p] << endl;
    return 0;
}