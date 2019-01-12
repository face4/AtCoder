#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
typedef long long ll;

#define inRange(x,a,b) (a <= x && x < b)
int dx[8] = {0,0,1,-1,1,1,-1,-1};
int dy[8] = {1,-1,0,0,1,-1,1,-1};

int main(){
    int h, w;
    cin >> h >> w;

    char mat[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
        }
    }

    bool visit[h][w];
    memset(visit, 0, sizeof(visit));

    ll ans = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(visit[i][j]) continue;
            queue<pair<int,int>> s;
            s.push({i,j});
            ll white = 0, black = 0;
            while(!s.empty()){
                auto p = s.front(); s.pop();
                if(visit[p.first][p.second])    continue;
                visit[p.first][p.second] = true;
                if(mat[p.first][p.second] == '.')   white++;
                else                                black++;
                for(int k = 0; k < 4; k++){
                    int di = p.first + dx[k], dj = p.second + dy[k];
                    if(inRange(di, 0, h) && inRange(dj, 0, w) && mat[di][dj]!=mat[p.first][p.second]){
                        s.push({di,dj});
                    }
                }
            }
            ans += black*white;
        }
    }

    cout << ans << endl;

    return 0;
}