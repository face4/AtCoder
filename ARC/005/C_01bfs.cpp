#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int INF = 1e9;

#define inRange(x,a,b) (a <= x && x < b)
int dx[8] = {0,0,1,-1,1,1,-1,-1};
int dy[8] = {1,-1,0,0,1,-1,1,-1};

int main(){
    int h, w;
    cin >> h >> w;

    char mat[h][w];
    int si, sj, gi, gj;
    int dist[h][w];

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
            dist[i][j] = INF;
            if(mat[i][j] == 's')    si = i, sj = j;
            if(mat[i][j] == 'g')    gi = i, gj = j;
        }
    }

    dist[si][sj] = 0;
    deque<pair<int,int>> q;
    q.push_back({si,sj});

    while(!q.empty()){
        pair<int,int> now = q.front();  q.pop_front();
        int i = now.first, j = now.second;

        if(i == gi && j == gj){
            if(dist[i][j] <= 2) cout << "YES" << endl;
            else    break;
            return 0;
        }
        for(int k = 0; k < 4; k++){
            int di = i + dx[k], dj = j + dy[k];
            if(!inRange(di, 0, h) || !inRange(dj, 0, w))    continue;
            int tmpc = dist[i][j] + (mat[di][dj] == '#');
            if(tmpc < dist[di][dj]){
                dist[di][dj] = tmpc;
                if(tmpc == dist[i][j])  q.push_front({di,dj});
                if(tmpc == dist[i][j]+1)    q.push_back({di,dj});
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}