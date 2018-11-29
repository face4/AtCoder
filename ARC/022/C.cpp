#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

vector<int> path[100000];

int bfs(int from){
    bool visit[100000] = {};
    int ret;
    queue<int> q;
    q.push(from);
    while(!q.empty()){
        int p = q.front(); q.pop();
        ret = p;
        visit[p] = true;
        for(int next : path[p]){
            if(!visit[next])    q.push(next);
        }
    }
    return ret;
}

int main(){
    int n;
    cin >> n;

    int a, b;
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        a--, b--;
        path[a].push_back(b);
        path[b].push_back(a);
    }

    int u = bfs(0);
    int v = bfs(u);

    cout << ++u << " " << ++v << endl;
    
    return 0;
}