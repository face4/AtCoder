// どうやったら綺麗に書けるのかわからない
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool vis[1000] = {}, flag = false;
vector<int> tmp, cycle, v[1000];

void dfs(int i){
    tmp.push_back(i);
    if(vis[i]){
        flag = true;
        cycle.clear();
        cycle.push_back(i);
        for(int j = tmp.size()-2; tmp[j] != i; j--)   cycle.push_back(tmp[j]);
        return;
    }
    vis[i] = true;
    for(int j : v[i]){
        dfs(j);
        if(flag)    return;
    }   
    vis[i] = false;
    tmp.pop_back();
}

bool ng(vector<int> &v){
    // 実装をさぼっているので相当遅い
    vector<int> indeg(1000, 0);
    for(int i : v){
        for(int j : ::v[i]){
            indeg[j]++;
        }
    }
    for(int i : v)  if(indeg[i] > 1)    return true;
    return false;
}

vector<int> reduce(const vector<int> &v){
    vector<int> ret;
    int n = v.size();
    vector<bool> d(1000, 0);
    for(int i : v)  d[i] = true;
    for(int i = 0; i < v.size(); i++){
        int k = -1;
        for(int j : ::v[v[i]]){
            if(d[j] && v[(i+1)%n] != j){
                k = j;
                break;
            }
        }
        if(k == -1) continue;
        bool f = false;
        for(int j = (i+1)%n;; j = (j+1)%n){
            if(v[j] == k)   f = true;
            if(f){
                ret.push_back(v[j]);
                if(v[j] == v[i])   return ret;
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    while(m-- > 0){
        int x, y;
        cin >> x >> y;
        v[--x].push_back(--y);
    }
    for(int i = 0; i < n; i++){
        dfs(i);
        if(flag)    break;
    }
    if(!flag){
        cout << -1 << endl;
        return 0;
    }
    reverse(cycle.begin(), cycle.end());
    while(ng(cycle)){
        cycle = reduce(cycle);
    }
    cout << cycle.size() << endl;
    for(int i : cycle)  cout << i+1 << endl;
    return 0;
}