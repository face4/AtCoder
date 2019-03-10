#include<iostream>
#include<vector>
#include<set>
using namespace std;

int n, x;
set<pair<int,int>> use;
set<int> h;
vector<int> v[100];
vector<pair<int,int>> path;
vector<bool> visit(100, 0);

void dfs(int pos){
    if(h.count(pos)){
        for(pair<int,int> trail : path){
            use.insert(trail);
        }
    }
    visit[pos] = true;
    for(int next : v[pos]){
        if(visit[next]) continue;
        path.push_back({min(pos, next), max(pos, next)});
        dfs(next);
        path.pop_back();
    }
}

int main(){
    cin >> n >> x;
    x--;

    int in;
    for(int i = 0; i < n; i++){
        cin >> in;
        if(in)  h.insert(i);
    }
    
    int a, b;
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        a--, b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(x);
    
    cout << 2*use.size() << endl;

    return 0;
}