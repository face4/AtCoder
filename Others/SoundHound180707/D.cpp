// 円とスヌークについてdijkstraを2本張る
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef long long ll;
const ll INF = 1ll<<60;

struct Edge{int to; ll cost;};

int n, m, s, t, u, v, a, b;

void dijkstra(int from, vector<vector<Edge>> &path, ll *dist){
    dist[from] = 0;
    priority_queue<pair<ll, int>> pq;

    pq.push({dist[from], from});

    while(!pq.empty()){
        pair<ll, int> now = pq.top();   pq.pop();
        ll c = -now.first;
        int pos = now.second;
        if(c > dist[pos])    continue;
        for(Edge e : path[pos]){
            if(dist[e.to] > c + e.cost){
                dist[e.to] = c + e.cost;
                pq.push({-dist[e.to], e.to});
            }
        }
    }

    return;
}

int main(){
    cin >> n >> m >> s >> t;
    s--, t--;
    vector<vector<Edge>> yen(n), snu(n);

    for(int i = 0; i < m; i++){
        cin >> u >> v >> a >> b;
        u--, v--;
        yen[u].push_back(Edge{v,a});
        yen[v].push_back(Edge{u,a});
        snu[u].push_back(Edge{v,b});
        snu[v].push_back(Edge{u,b});
    }

    ll dijky[n], dijks[n];
    for(int i = 0; i < n; i++)  dijky[i] = dijks[i] = INF;

    dijkstra(s, yen, dijky);
    dijkstra(t, snu, dijks);

    ll ans[n];
    ans[n-1] = dijky[n-1]+dijks[n-1];

    for(int i = n-2; i >= 0; i--){
        ans[i] = min(ans[i+1], dijky[i]+dijks[i]);
    }

    for(int i = 0; i < n; i++){
        cout << 1000000000000000-ans[i] << endl;
    }
    return 0;
}