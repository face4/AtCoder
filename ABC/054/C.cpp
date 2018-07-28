#include<iostream>
using namespace std;

int cnt = 0;
bool path[9][9] = {};
int n, m;

void solve(int before, bool visit[]){
    bool judge = true;
    for(int i = 1; i <= n; i++){
        if(!visit[i])   judge = false;
    }

    if(judge){
        cnt++;
        return;
    }

    for(int j = 1; j <= n; j++){
        if(path[before][j] && !visit[j]){
            visit[j] = true;
            solve(j, visit);
            visit[j] = false;
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        path[a][b] = path[b][a] = true;
    }

    bool visit[n+1];
    for(int i = 1; i <= n; i++)  visit[i] = false;
    visit[1] = true;
    
    solve(1, visit);
    cout << cnt << endl;
    return 0;
}