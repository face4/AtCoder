#include<iostream>
#include<vector>
#include<map>
#include<set>
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
        if(x != p[x])   p[x] = parent(p[x]);
        return p[x];
    }

    void unite(int x, int y){
        x = parent(x), y = parent(y);
        if(x == y)  return;
        p[x] = y;
    }
};

int base = 100005;

typedef long long ll;

int main(){
    UF uf(200100);
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    map<int,int> xcnt, ycnt;
    set<int> xset, yset;
    for(int i = 0; i < n; i++)  cin >> x[i] >> y[i], uf.unite(x[i], y[i]+base), xset.insert(x[i]), yset.insert(y[i]);
    for(int p : xset)   xcnt[uf.parent(p)]++;
    for(int p : yset)   ycnt[uf.parent(p+base)]++;
    ll ans = 0;
    for(auto p : xcnt){
        ans += (ll)p.second * ycnt[p.first];
    }
    cout << ans-n << endl;
    return 0;
}