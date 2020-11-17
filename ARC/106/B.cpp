#include<iostream>
#include<vector>
using namespace std;

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

typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;
    UF uf(n);
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++)  cin >> a[i];
    for(int i = 0; i < n; i++)  cin >> b[i];
    while(m--){
        int c, d;
        cin >> c >> d;
        uf.unite(--c, --d);
    }
    vector<ll> re(n, 0), id(n, 0);
    for(int i = 0; i < n; i++){
        int par = uf.parent(i);
        re[par] += a[i];
        id[par] += b[i];
    }
    for(int i = 0; i < n; i++){
        if(re[i] != id[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}