// editorial
#include<iostream>
#include<vector>
#include<set>
using namespace std;

// 簡易UF
struct UF{
    vector<int> p, m;
    int n;

    UF(int siz){
        n = siz;
        p.resize(n, 0);
        m.resize(n, 1);
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
        m[y] += m[x];
        p[x] = y;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> x(n), y(n), xrev(n), yrev(n);
    for(int i = 0; i < n; i++)  cin >> x[i] >> y[i], xrev[--x[i]] = i, yrev[--y[i]] = i;
    set<int> s; // y-axis
    UF uf(n);
    for(int i = 0; i < n; i++){
        int ind = xrev[i];
        if(!s.empty() && *s.begin() < y[ind]){
            uf.unite(yrev[*s.begin()], ind);
            auto it = s.begin();
            it++;
            while(it != s.end() && *it < y[ind]){
                uf.unite(yrev[*it], ind);
                it = s.erase(it);
            }
        }else{
            s.insert(y[ind]);
        }
    }
    for(int i = 0; i < n; i++)  cout << uf.m[uf.parent(i)] << endl;
    return 0;
}