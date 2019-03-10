#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
ll tmp;

class DisjointSet{
  public:
    vector<int> num, p;

    DisjointSet(){}
    DisjointSet(int size){
        num.resize(size, 0);
        p.resize(size, 0);
        for(int i = 0; i < size; i++) makeSet(i);
    }

    void makeSet(int x){
        p[x] = x;
        num[x] = 1;
    }

    bool same(int x, int y){
        return findSet(x) == findSet(y);
    }
    
    void unite(int x, int y){
        link(findSet(x), findSet(y));
    }

    void link(int x, int y){
        if(x == y)  return;
        p[y] = x;
        tmp -= (ll)(num[x])*num[y];
        num[x] += num[y];
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
    int n, m;
    cin >> n >> m;

    DisjointSet uf(n);

    int a, b;
    vector<pair<int,int>> v;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--, b--;
        v.push_back({a,b});
    }

    vector<ll> ans(m, 0);
    tmp = (ll)n*(n-1)/2;
    reverse(v.begin(), v.end());

    for(int i = 0; i < m; i++){
        ans[m-1-i] = tmp;
        if(i != m-1){
            uf.unite(v[i].first, v[i].second);
        }
    }

    for(int i = 0; i < m; i++)  cout << ans[i] << endl;
    
    return 0;
}