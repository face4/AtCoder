#include<iostream>
#include<queue>
using namespace std;

#define inRange(x,a,b) a <= x && x < b

int h, w;
char mat[50][50];
bool visit[50][50] = {};
int dx[4] = {-1,0,0,1};
int dy[4] = {0,1,-1,0};

int main(){
    cin >> h >> w;

    int white = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
            if(mat[i][j] == '.')    white++;
        }
    }
    
    int dist = -1;
    queue<pair<pair<int,int>,int>> q;

    if(mat[0][0] == '.')    q.push({{0,0}, 0});
    
    while(!q.empty()){
        pair<pair<int,int>,int> x = q.front();    q.pop();
        if(x.first.first == h-1 && x.first.second == w-1){
            dist = x.second;
            break;
        }

        if(visit[x.first.first][x.first.second])    continue;

        visit[x.first.first][x.first.second] = true;

        for(int i = 0; i < 4; i++){
            int ni = x.first.first + dx[i];
            int nj = x.first.second + dy[i];
            if(inRange(ni, 0, h) && inRange(nj, 0, w) && !visit[ni][nj] && mat[ni][nj] == '.'){
                q.push({{ni,nj}, x.second+1});
            }
        }
    }

    cout << (dist == -1 ? -1 : white-dist-1) << endl;

    return 0;
}