#include<iostream>
using namespace std;

int uf[100001], p[100001];
int n,m,x,y;

void init(){
    for(int i = 1; i <= n; i++)  uf[i] = i;
}

int root(int x){
    if(uf[x] == x){
        return x;
    }else{
        return uf[x] = root(uf[x]);
    }
}

bool same(int x, int y){
    return root(x) == root(y);
}

void unite(int x, int y){
    x = root(x);
    y = root(y);
    if(x == y) return;
    uf[x] = y;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> p[i];
    init();
    for(int i = 1; i <= m; i++){
        cin >> x >> y;
        unite(x,y);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(same(i, p[i]))   ans++;
    }

    cout << ans << endl;
    return 0;
}