#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll INF = 1ll<<55;

int main(){
    int n, m, t;
    cin >> n >> m >> t;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)  cin >> a[i];
    vector<pii> v[n], rv[n];
    int x, y, z;
    while(m-- > 0){
        cin >> x >> y >> z;
        x--, y--;
        v[x].push_back({y, z});
        rv[y].push_back({x, z});
    }
    vector<ll> dist(n, INF), rdist(n, INF);
    priority_queue<pair<ll, int>> pq;
    pq.push({-0, 0});
    while(!pq.empty()){
        pair<ll, int> p = pq.top(); pq.pop();
        ll cost = -p.first;
        int i = p.second;
        if(cost >= dist[i]) continue;
        dist[i] = cost;
        for(pair<int,int> next : v[i]){
            ll tmpc = cost + next.second;
            if(tmpc < dist[next.first]){
                pq.push({-tmpc, next.first});
            }
        }
    }
    pq.push({-0, 0});
    while(!pq.empty()){
        pair<ll, int> p = pq.top(); pq.pop();
        ll cost = -p.first;
        int i = p.second;
        if(cost >= rdist[i]) continue;
        rdist[i] = cost;
        for(pair<int,int> next : rv[i]){
            ll tmpc = cost + next.second;
            if(tmpc < rdist[next.first]){
                pq.push({-tmpc, next.first});
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(dist[i]+rdist[i] > t)    continue;
        ans = max(ans, (t-dist[i]-rdist[i])*a[i]);
    }
    cout << ans << endl;
    return 0;
}