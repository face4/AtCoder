#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> p(100000), siz(100000, 1);
int n, m;
vector<pair<int,int>> path[200001], person[200001];

void init(){
    for(int i = 0; i < 100000; i++){
        p[i] = i;
    }
}

int findSet(int x){
    if(p[x] != x){
        p[x] = findSet(p[x]);
    }
    return p[x];
}

void unite(int i, int j){
    int pi = findSet(i), pj = findSet(j);
    if(pi == pj)    return;
    if(siz[pi] > siz[pj]){
        siz[pi] += siz[pj];
        p[pj] = pi;
    }else{
        siz[pj] += siz[pi];
        p[pi] = pj;
    }
}

bool same(int i, int j){
    return findSet(i) == findSet(j);
}

int main(){
    init();
    cin >> n >> m;
    
    int a, b, y;
    while(m-- > 0){
        cin >> a >> b >> y;
        a--, b--;
        path[y].push_back({a,b});
    }

    int q;
    cin >> q;

    int v, w;
    for(int i = 0; i < q; i++){
        cin >> v >> w;
        v--;
        person[w].push_back({v, i});
    }

    vector<int> ans(q);

    for(int i = 200000; i >= 0; i--){
        for(pair<int,int> tmp : person[i]){
            ans[tmp.second] = siz[findSet(tmp.first)];
        }
        for(pair<int,int> tmp : path[i]){
            unite(tmp.first, tmp.second);
        }
    }

    for(int x : ans)    cout << x << endl;

    return 0;
}
