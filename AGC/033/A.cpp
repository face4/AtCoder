#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)
int di[8] = {0,0,1,-1,1,1,-1,-1};
int dj[8] = {1,-1,0,0,1,-1,1,-1};

int main(){
    int h, w;
    cin >> h >> w;
    char mat[h][w];
    queue<pair<pair<int,int>,int>> q;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
            if(mat[i][j] == '#')    q.push({{i,j},0});
        }
    }
    vector<vector<int>> d(h, vector<int>(w, 1<<30));
    int ans = 0;
    while(!q.empty()){
        auto p = q.front(); q.pop();
        int i = p.first.first, j = p.first.second, c = p.second;
        if(d[i][j] <= c)    continue;
        d[i][j] = c;
        ans = max(ans, c);
        for(int k = 0; k < 4; k++){
            int ni = i+di[k], nj = j+dj[k];
            if(inRange(ni,0,h) && inRange(nj,0,w) && mat[ni][nj]=='.' && c+1 < d[ni][nj]){
                q.push({{ni,nj},c+1});
            }
        }
    }
    cout << ans << endl;
    return 0;
}