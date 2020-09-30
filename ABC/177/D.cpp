#include<iostream>
#include<vector>
using namespace std;

// 簡易UF
struct UF{
    vector<int> p, rank;
    int n;

    UF(int siz){
        n = siz;
        p.resize(n, 0);
        rank.resize(n, 1);
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
        if(x == y)  return;
        rank[y] += rank[x];
        p[x] = y;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    UF uf(n);
    while(m--){
        int a, b;
        cin >> a >> b;
        a--, b--;
        uf.unite(a, b);
    }
    int ret = 0;
    for(int i = 0; i < n; i++)  ret = max(ret, uf.rank[i]);
    cout << ret << endl;
    return 0;
}