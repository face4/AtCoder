#include<iostream>
#include<cctype>
#include<vector>
#include<set>
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
        if(x > y)   swap(x, y);
        p[y] = x;
    }

    int findSet(int x){
        if(x != p[x]){
            // path compression
            p[x] = findSet(p[x]);
        }
        return p[x];
    }
};

int enc(char x){
    if(isdigit(x))  return x - '0';
    else            return x - 'A' + 10;
}

typedef long long ll;

int main(){
    int n;
    string s, t;
    cin >> n >> s >> t;

    DisjointSet uf(38);

    set<char> appear;
    for(int i = 0; i < n; i++){
        uf.unite(enc(s[i]), enc(t[i]));
        if(!isdigit(s[i]))  appear.insert(s[i]);
        if(!isdigit(t[i]))  appear.insert(t[i]);
    }

    uf.unite(36, enc(s[0]));
    uf.unite(36, enc(t[0]));

    ll ans = 1;
    for(char x : appear){
        int i = x - 'A' + 10;
        if(uf.same(i, 37))  continue;
        
        bool isNumber = false;
        for(int j = 0; j < 10; j++) if(uf.same(i, j))   isNumber = true;
        if(isNumber)    continue;

        if(uf.same(36, i))  ans *= 9;
        else                ans *= 10;

        uf.unite(i, 37);
    }

    cout << ans << endl;

    return 0;
}