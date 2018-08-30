#include<iostream>
#include<queue>
using namespace std;
#define inRange(x,a,b) a <= x && x < b

int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};

int island = 0;
char mat[10][10];

bool bfs(int i, int j){
    bool visit[10][10] = {};
    queue<pair<int,int>> s;
    s.push({i,j});

    int cnt = 0;
    while(!s.empty()){
        pair<int,int> now = s.front(); s.pop();
        if(visit[now.first][now.second])    continue;
        visit[now.first][now.second] = true;
        cnt++;

        for(int k = 0; k < 4; k++){
            int ni = now.first + dx[k];
            int nj = now.second + dy[k];
            if(inRange(ni,0,10) && inRange(nj,0,10) && !visit[ni][nj] && mat[ni][nj] == 'o')
                s.push({ni,nj});
        }
    }
    
    return cnt == island+1;
}

int main(){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cin >> mat[i][j];
            if(mat[i][j] == 'o')    island++;
        }
    }

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(mat[i][j] == 'x' && bfs(i,j)){
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}