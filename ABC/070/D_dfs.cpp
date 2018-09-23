#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
struct edge{
    int to;
    ll cost;
    edge(int t, ll c) : to(t), cost(c) {}
};

vector<edge> tree[100001];
ll d[100001];

void dfs(int v, int p, ll c){
    d[v] = c;
    for(edge e : tree[v]){
        if(e.to == p)   continue;
        dfs(e.to, v, c+e.cost);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    
    int a, b;
    ll c;
    for(int i = 1; i < n; i++){
        scanf("%d %d %lld", &a, &b, &c);
        a--, b--;
        tree[a].push_back(edge(b,c));
        tree[b].push_back(edge(a,c));
    }

    int q, k;
    scanf("%d %d", &q, &k);

    dfs(--k, -1, 0);

    int x, y;
    for(int i = 0; i < q; i++){
        scanf("%d %d", &x, &y);
        printf("%lld\n", d[--x]+d[--y]);
    }

    return 0;
}