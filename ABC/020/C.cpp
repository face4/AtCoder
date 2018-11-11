#include<iostream>
#include<queue>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)

const int INF = 1000000005;

int h, w, t;
int si, sj, gi, gj;
char mat[10][10];
int dist[10][10];
int dx[8] = {0,0,1,-1,1,1,-1,-1};
int dy[8] = {1,-1,0,0,1,-1,1,-1};

bool f(int x){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            dist[i][j] = INF;
        }
    }

    priority_queue<pair<int, pair<int,int>>> s;
    s.push({0, {si,sj}});

    while(!s.empty()){
        pair<int,pair<int,int>> now = s.top();    s.pop();
        pair<int,int> p = now.second;
        int cost = -now.first;

        if(p.first == gi && p.second == gj) return cost <= t;

        if(cost >= dist[p.first][p.second]) continue;

        dist[p.first][p.second] = cost;

        for(int k = 0; k < 4; k++){
            int ni = p.first + dx[k], nj = p.second + dy[k];
            if(!inRange(ni,0,h) || !inRange(nj,0,w))    continue;
            int move = (mat[ni][nj] == '#') ? x : 1;
            if(cost + move < dist[ni][nj])  s.push({-(cost+move), {ni,nj}});
        }
    }

    return false;
}

int main(){
    cin >> h >> w >> t;

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
            if(mat[i][j] == 'S')   si = i, sj = j;
            if(mat[i][j] == 'G')    gi = i, gj = j;
        }
    }

    int l = 1, r = t+1;
    while(r-l > 1){
        int mid = (l+r)/2;
        if(f(mid))  l = mid;
        else        r = mid;
    }

    cout << l << endl;

    return 0;
}