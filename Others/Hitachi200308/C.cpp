// editorial
// 思いつける気がしない
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> v[2];
vector<int> g[200000];

void dfs(int x, int p, int k){
    v[k].push_back(x);
    for(int next : g[x]){
        if(next == p)   continue;
        dfs(next, x, 1-k);
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, -1, 0);
    if(v[0].size() > v[1].size())   swap(v[0], v[1]);
    vector<int> ans(n, 0);
    queue<int> q[3];
    for(int i = 1; i <= n; i++) q[i%3].push(i);
    if(v[0].size() >= q[1].size()){
        for(int x : v[0]){
            if(q[1].empty())    ans[x] = q[0].front(), q[0].pop();
            else                ans[x] = q[1].front(), q[1].pop();
        }
        for(int x : v[1]){
            if(q[2].empty())    ans[x] = q[0].front(), q[0].pop();
            else                ans[x] = q[2].front(), q[2].pop();
        }
    }else{
        for(int x : v[0])   ans[x] = q[0].front(), q[0].pop();
        for(int x : v[1]){
            for(int i = 0; i < 3; i++){
                if(q[i].empty())    continue;
                ans[x] = q[i].front();  q[i].pop();
                break;
            }
        }
    }
    for(int i = 0; i < n; i++)  cout << ans[i] << " \n"[i==n-1];
    return 0;
}