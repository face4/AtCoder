#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
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

int main(){
    int n;
    cin >> n;
    double x[n], y[n];
    for(int i = 0; i < n; i++)  cin >> x[i] >> y[i];
    auto f = [&](int i, int j)->double{
        return sqrt(pow(x[i]-x[j],2.0)+pow(y[i]-y[j],2.0));
    };
    int UP = n, DO = n+1;
    double l = 0.0, r = 1e10;
    for(int i = 0; i < 200; i++){
        double mid = (l+r)/2;
        UF uf(n+2);
        for(int j = 0; j < n; j++){
            if(100-y[j] < mid)  uf.unite(UP, j);
            if(y[j]-(-100) < mid)   uf.unite(DO, j);
            for(int k = j+1; k < n; k++){
                if(f(j, k) < mid)    uf.unite(j, k);
            }
        }
        if(uf.same(UP, DO)) r = mid;
        else                l = mid;
    }
    cout << fixed << setprecision(12) << l/2 << endl;
    return 0;
}