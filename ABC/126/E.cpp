#include<iostream>
#include<vector>
#include<set>
using namespace std;

class UF{
  public:
    vector<int> rank, p;

    UF(){}
    UF(int size){
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
    
    void unite(int x, int y){
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
            p[x] = findSet(p[x]);
        }
        return p[x];
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    UF uf(n);
    int x, y, z;
    for(int i = 0; i < m; i++){
        cin >> x >> y >> z;
        x--, y--;
        uf.unite(x,y);
    }
    set<int> res;
    for(int i = 0; i < n; i++)  res.insert(uf.findSet(i));
    cout << res.size() << endl;
    return 0;
}