#include<iostream>
#include<vector>
using namespace std;

// 簡易UF
struct UF{
    vector<int> p, cnt;
    int n;

    UF(int siz){
        n = siz;
        p.resize(n, 0);
        cnt.resize(n, 1);
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
        cnt[y] += cnt[x];
        p[x] = y;
    }
};

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> ans(n, 0), deg(n, 0);
    UF uf(n);
    while(m--){
        int a, b;
        cin >> a >> b;
        a--, b--;
        uf.unite(a, b);
        deg[a]++, deg[b]++;
    }
    for(int i = 0; i < n; i++)  ans[i] = uf.cnt[uf.parent(i)]-deg[i]-1;
    while(k--){
        int a, b;
        cin >> a >> b;
        a--, b--;
        if(uf.same(a, b)){
            ans[a]--, ans[b]--;
        }
    }
    for(int i = 0; i < n; i++)  cout << ans[i] << " \n"[i==n-1];
    return 0;
}