#include<iostream>
#include<vector>
#include<map>
using namespace std;

class DisjointSet{
  public:
    vector<int> rank, p;

    DisjointSet(){}
    DisjointSet(int size){
        rank.resize(size, 0);
        p.resize(size, 0);
        for(int i = 0; i < size; i++) makeSet(i);
    }

    void makeSet(int x){
        p[x] = x;
        rank[x] = 0;
    }

    bool same(int x, int y){
        return findSet(x) == findSet(y);
    }
    
    bool unite(int x, int y){
        link(findSet(x), findSet(y));
    }

    void link(int x, int y){
        if(rank[x] > rank[y]){
            p[y] = x;
        }else{
            p[x] = y;
            if(rank[x] == rank[y]){
                rank[y]++;
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
    int n, k, l, p, q;
    cin >> n >> k >> l;
    
    DisjointSet road(n), train(n);

    for(int i = 0; i < k; i++){
        cin >> p >> q;
        p--; q--;
        road.unite(p, q);
    }

    for(int i = 0; i < l; i++){
        cin >> p >> q;
        p--; q--;
        train.unite(p,q);
    }

    int a[n], b[n];
    for(int i = 0; i < n; i++)  a[i] = road.findSet(i);
    for(int i = 0; i < n; i++)  b[i] = train.findSet(i);

    map<pair<int,int>, int> ans;
    for(int i = 0; i < n; i++){
        ans[{a[i],b[i]}]++;
    }

    for(int i = 0; i < n; i++){
        if(i)   cout << " ";
        cout << max(1, ans[{a[i],b[i]}]);
    }
    cout << endl;

    return 0;
}