#include<iostream>
#include<queue>
using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};

int main(){
    int r, c, si, sj, gi, gj;
    cin >> r >> c >> si >> sj >> gi >> gj;

    char mat[r+1][c+1];
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cin >> mat[i][j];
        }
    }

    queue<pair<pair<int,int>, int>> q;
    q.push({{si,sj},0});
    bool visit[r][c] = {};

    int depth;
    while(!q.empty()){
        pair<int,int> now = q.front().first;
        depth = q.front().second;
        q.pop();

        if(now.first == gi && now.second == gj) break;
        if(visit[now.first][now.second])    continue;

        visit[now.first][now.second] = true;

        for(int i = 0; i < 4; i++){
            int ni = now.first + dx[i];
            int nj = now.second + dy[i];

            if(mat[ni][nj] == '.' && !visit[ni][nj]){
                q.push({{ni,nj}, depth+1});
            }
        }    
    }

    cout << depth << endl;

    return 0;
}