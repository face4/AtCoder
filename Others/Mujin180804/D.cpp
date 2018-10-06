// WAの原因がわかりません！！
#include<iostream>
#include<vector>
#include<cstring>
#include<stack>
using namespace std;
#define inRange(x, a, b) (a <= x && x <= b)

bool visit[1000][1000] = {};
vector<pair<int,int>> path[1000][1000];
int ans = 0;
int n, m;

int rev(int x){
    int ret = 0;
    while(x > 0){
        ret = ret*10 + x%10;
        x /= 10;
    }
    return ret;
}

void dfs(int i, int j){
    visit[i][j] = true;

    int ni = i, nj = j;
    if(ni == 0 || nj == 0)   return;
    
    if(ni < nj) ni = rev(ni);
    else        nj = rev(nj);
    
    if(ni < nj)     nj -= ni;
    else            ni -= nj;
    
    path[ni][nj].push_back({i,j});
    
    if(!visit[ni][nj])  dfs(ni,nj);
}

void bfs(int i, int j){
    stack<pair<int,int>> s;
    s.push({i,j});

    while(!s.empty()){
        pair<int,int> now = s.top(); s.pop();
        int ni = now.first, nj = now.second;
        if(visit[ni][nj])   continue;

        if(inRange(ni, 1, n) && inRange(nj, 1, m))  ans++;
        visit[ni][nj] = true;
        for(pair<int,int> next : path[ni][nj]){
            if(!visit[next.first][next.second]) s.push({next.first, next.second});
        }
    }

}

int main(){
    cin >> n >> m;

    for(int i = n; i >= 1; i--){
        for(int j = m; j >= 1; j--){
            if(!visit[i][j])    dfs(i,j);
        }
    }

    memset(visit, 0, sizeof(visit));
    
    for(int i = 0; i <= n; i++) bfs(i, 0);
    for(int j = 0; j <= m; j++) bfs(0, j);

    cout << n*m - ans << endl;

    return 0;
}