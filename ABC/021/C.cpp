#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9+7;

int main(){
    int n, a, b, m, x, y;
    cin >> n >> a >> b;
    vector<int> path[n];
    a--, b--;
    cin >> m;
    while(m-- > 0){
        cin >> x >> y;
        x--, y--;
        path[x].push_back(y);
        path[y].push_back(x);
    }
    vector<int> dist(n, INF);
    priority_queue<pair<int,int>> pq;
    pq.push({-0, a});
    while(!pq.empty()){
        pair<int,int> p = pq.top(); pq.pop();
        int c = -p.first , now = p.second;
        if(c >= dist[now])  continue;
        dist[now] = c;
        for(int next : path[now]){
            if(c+1 < dist[next])    pq.push({-(c+1), next});
        }
    }
    vector<int> dp(n, 0);
    vector<bool> visit(n, 0);
    dp[a] = 1;
    queue<int> q;
    q.push(a);
    while(!q.empty()){
        int now = q.front();    q.pop();
        if(visit[now])  continue;
        visit[now] = true;
        for(int next : path[now]){
            if(dist[now]+1 == dist[next]){
                dp[next] += dp[now];
                dp[next] %= MOD;
                q.push(next);
            }
        }
    }
    cout << dp[b] << endl;
    return 0;
}