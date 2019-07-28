#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<climits>
using namespace std;
#define NODENUM 101010

vector<int> depth(NODENUM, 0), va[NODENUM];
vector<vector<int>> par(30, vector<int>(NODENUM));
int n;

void dfs(int now, int p, int d){
    par[0][now] = p;
    depth[now] = d;
    for(int child : va[now]){
        if(child == p)  continue;
        dfs(child, now, d+1);
    }
}

void init(){
    dfs(0, -1, 0);
    for(int k = 0; k+1 < 30; k++){
        for(int i = 0; i < n; i++){
            if(par[k][i] < 0)   par[k+1][i] = -1;
            else                par[k+1][i] = par[k][par[k][i]];
        }
    }
}

int lca(int u, int v){
    // make v deeper
    if(depth[u] > depth[v]) swap(u, v);
    for(int k = 0; k < 30; k++){
        // depth(v)-depth(u) is equal to or bigger than 2^k
        if(((depth[v]-depth[u])>>k)&1){
            v = par[k][v];
        }
    }
    if(u == v)  return u;
    for(int k = 30-1; k >= 0; k--){
        if(par[k][u] != par[k][v]){
            u = par[k][u];
            v = par[k][v];
        }
    }
    return par[0][u];
}

struct data{
    int num, sum;
    data(){
        num = 0, sum = 0;
    }
};

typedef long long ll;

// ?
int main(){
    int Q;
    scanf("%d %d\n", &n, &Q);

    vector<pair<pair<int,int>,int>> v[n];
    for(int i = 0; i < n-1; i++){
        int a, b, c, d;
        scanf("%d %d %d %d\n", &a, &b, &c, &d);
        a--, b--;
        v[a].push_back({{b, d}, c});    va[a].push_back(b);
        v[b].push_back({{a, d}, c});    va[b].push_back(a);
    }
    init();

    map<int, data> dat[n];
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int pos = q.front(); q.pop();
        for(auto next : v[pos]){
            int to = next.first.first, nc = dist[pos] + next.first.second, col = next.second;
            if(dist[to] != INT_MAX)   continue;
            dat[to] = dat[pos];
            if(dat[to].count(col) == 0) dat[to][col] = data();
            dat[to][col].num++;
            dat[to][col].sum += next.first.second;
            dist[to] = nc;
            q.push(to);
        }
    }

    while(Q-- > 0){
        int x, y, u, vv;
        scanf("%d %d %d %d\n", &x, &y, &u, &vv);
        u--, vv--;
        int mom = lca(u, vv);
        ll ans = dist[u] + dist[vv];
        if(dat[u].count(x)) ans = ans - dat[u][x].sum + (ll)(dat[u][x].num) * y;
        if(dat[vv].count(x)) ans = ans - dat[vv][x].sum + (ll)(dat[vv][x].num) * y;
        ll sub = dist[mom];
        if(dat[mom].count(x)) sub = sub - dat[mom][x].sum + (ll)dat[mom][x].num * y;
        ans -= 2*sub;
        printf("%lld\n", ans);
    }

    return 0;
}