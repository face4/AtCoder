#include<iostream>
#include<vector>
#include<set>
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

int main(){
    int n, m;
    cin >> n >> m;
    UF uf(n);
    while(m--){
        int a, b;
        cin >> a >> b;
        a--, b--;
        uf.unite(a,b);
    }
    set<int> ps;
    for(int i = 0; i < n; i++)  ps.insert(uf.parent(i));
    cout << ps.size()-1 << endl;
    return 0;
}