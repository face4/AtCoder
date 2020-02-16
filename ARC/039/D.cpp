#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

// 簡易UF
struct UF{
    vector<int> p;
    int n;

    UF(int siz){
        n = siz;
        p.resize(n, 0);
        for(int i = 0; i < n; i++)  p[i] = i;
    }

    int parent(int x){
        if(p[x] != x)   p[x] = parent(p[x]);
        return p[x];
    }

    bool same(int x, int y){
        return parent(x) == parent(y);
    }
    
    void unite(int x, int y){
        x = parent(x), y = parent(y);
        p[x] = y;
    }
};

struct LCA{
    int n, bit; // n < 1<<bit
    vector<int> depth;
    vector<vector<int>> par, v;

    LCA(int n) : n(n){
        depth.resize(n, -1);
        bit = 0;
        while(1<<bit <= n)  bit++;
        par.resize(bit);
        for(int i = 0; i < bit; i++)    par[i].resize(n);
        v.resize(n);
    }

    void add_edge(int a, int b){
        v[a].push_back(b);
        v[b].push_back(a);
    }

    void dfs(int now, int p, int d){
        par[0][now] = p;
        depth[now] = d;
        for(int child : v[now]){
            if(child == p)  continue;
            dfs(child, now, d+1);
        }
    }

    void build(){
        for(int i = 0; i < n; i++){
            if(depth[i] == -1)    dfs(i, -1, 0);
        }
        for(int k = 0; k+1 < bit; k++){
            for(int i = 0; i < n; i++){
                if(par[k][i] < 0)   par[k+1][i] = -1;
                else                par[k+1][i] = par[k][par[k][i]];
            }
        }
    }

    int lca(int a, int b){
        // make b deeper
        if(depth[a] > depth[b]) swap(a, b);
        for(int k = 0; k < 30; k++){
            // depth(b)-depth(a) is equal to or bigger than 2^k
            if(((depth[b]-depth[a])>>k)&1){
                b = par[k][b];
            }
        }
        if(a == b)  return a;
        for(int k = bit-1; k >= 0; k--){
            if(par[k][a] != par[k][b]){
                a = par[k][a];
                b = par[k][b];
            }
        }
        return par[0][a];
    }

    int dist(int a, int b){
        int l = lca(a, b);
        return depth[a]-depth[l] + depth[b]-depth[l];
    }
};

// 無向グラフの橋の検出
vector<int> ord(100000), low(100000), v[100000];
vector<bool> vis(100000, 0);

void dfs(int x, int p, int &k){
    ord[x] = low[x] = k++;
    vis[x] = true;
    for(int j : v[x]){
        if(vis[j]){
            if(j != p)  low[x] = min(low[x], ord[j]);
        }else{
            dfs(j, x, k);
            low[x] = min(low[x], low[j]);
        }
    }
}

typedef pair<int,int> pii;

int main(){
    int n, m;
    cin >> n >> m;
    vector<pii> vp;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        v[a].push_back(b);
        v[b].push_back(a);
        if(a > b)   swap(a, b);
        vp.push_back({a, b});
    }
    int k = 0;
    dfs(0, -1, k);
    sort(vp.begin(), vp.end());
    UF uf(n);
    for(pii p : vp){
        int x = p.first, y = p.second;
        if(ord[x] > ord[y]) swap(x, y);
        if(ord[x] >= low[y]) uf.unite(x, y);
    }
    set<pii> e;
    for(pii p : vp){
        int x = uf.parent(p.first), y = uf.parent(p.second);
        if(x != y)  e.insert({min(x,y), max(x,y)});
    }
    LCA l(n);
    for(pii p : e){
        l.add_edge(p.first, p.second);
    }
    l.build();
    int q;
    cin >> q;
    while(q--){
        int a, b, c;
        cin >> a >> b >> c;
        a = uf.parent(--a);
        b = uf.parent(--b);
        c = uf.parent(--c);
        bool ok = a==b && b == c;
        ok |= l.dist(a, b) + l.dist(b, c) == l.dist(a, c);
        cout << (ok ? "OK" : "NG") << endl;
    }
    return 0;
}