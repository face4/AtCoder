#include<iostream>
#include<set>
#include<vector>
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
    int n, m, a, b;
    scanf("%d %d", &n, &m);

    DisjointSet uf(n);

    for(int i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        uf.unite(--a,--b);
    }

    set<int> s;
    for(int i = 0; i < n; i++)  s.insert(uf.findSet(i));

    cout << s.size()-1 << endl;

    return 0;
}