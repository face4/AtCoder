#include<iostream>
#include<vector>
#include<map>
using namespace std;

typedef pair<int,int> pii;
vector<int> c;

class DisjointSet{
  public:
    vector<int> p;
    vector<map<int,int>> g;

    DisjointSet(){}
    DisjointSet(int size){
        // rank.resize(size, 0);
        p.resize(size, 0);
        for(int i = 0; i < size; i++) makeSet(i);
    }

    void makeSet(int x){
        p[x] = x;
        // rank[x] = 0;
        g.push_back(map<int,int>());
        g[x][c[x]] = 1;
    }

    bool same(int x, int y){
        return findSet(x) == findSet(y);
    }
    
    void unite(int x, int y){
        link(findSet(x), findSet(y));
    }

    void link(int x, int y){
        if(x == y)  return;
        if(g[x].size() > g[y].size()){
            p[y] = x;
            for(pii p : g[y]){
                g[x][p.first] += p.second;
            }
        }else{
            p[x] = y;
            for(pii p : g[x]){
                g[y][p.first] += p.second;
            }
        }
    }

    int findSet(int x){
        if(x != p[x]){
            // path compression
            p[x] = findSet(p[x]);
        }
        return p[x];
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    c.resize(n);
    for(int i = 0; i < n; i++)  cin >> c[i], c[i]--;
    DisjointSet uf(n);
    for(int i = 0; i < q; i++){
        int op, a, b;
        cin >> op >> a >> b;
        a--, b--;
        if(op == 1){
            uf.unite(a, b);
        }else if(op == 2){
            int par = uf.findSet(a);
            cout << (uf.g[par].count(b) ? uf.g[par][b] : 0) << endl;
        }
    }
    return 0;
}