#include<iostream>
#include<queue>
#include<vector>
using namespace std;

typedef long long ll;
const ll INF = 1ll<<60;

int main(){
    int n;
    cin >> n;

    vector<vector<pair<int, int>>> path(n);
    int a, b, c;
    for(int i = 1; i < n; i++){
        cin >> a >> b >> c;
        a--; b--;
        path[a].push_back({b, c});
        path[b].push_back({a, c});
    }

    int q, k;
    cin >> q >> k;
    k--;

    ll d[n];
    for(int i = 0; i < n; i++)  d[i] = INF;
    d[k] = 0ll;

    priority_queue<pair<ll,int>> pq;
    for(int i = 0; i < n; i++)  pq.push({-d[i], i});

    while(!pq.empty()){
        pair<ll,int> now = pq.top();   pq.pop();
        ll tmpdist = -now.first;
        int pos = now.second;
        if(d[pos] < tmpdist)    continue;
        d[pos] = tmpdist;
        for(pair<int,int> p : path[pos]){
            int next = p.first;
            int cost = p.second;
            if(d[next] > tmpdist + cost){
                pq.push({-(tmpdist+cost), next});
            }
        }
    }

    int x, y;
    while(q-- > 0){
        cin >> x >> y;
        cout << d[--x] + d[--y] << endl;
    }

    return 0;
}