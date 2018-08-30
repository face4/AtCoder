#include<iostream>
#include<queue>
using namespace std;

vector<vector<int>> path(101);
bool visit[101] = {};

bool bfs(int start){
    queue<pair<int,int>> s;
    s.push({0,start});

    while(!s.empty()){
        int next = s.front().second;
        int before = s.front().first;
        s.pop();
        
        if(visit[next]) return false;

        visit[next] = true;

        for(int x : path[next]){
            if(x == before) continue;
            if(visit[x])    return false;
            else            s.push({next,x});
        } 
    }

    return true;
}

int main(){
    int n, m, a, b;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(!visit[i] && bfs(i)) ans++;
    }

    cout << ans << endl;

    return 0;
}