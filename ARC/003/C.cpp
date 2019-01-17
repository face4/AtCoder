#include<iostream>
#include<iomanip>
#include<queue>
#include<cstring>
using namespace std;

#define inRange(x,a,b) (a <= x && x < b)
int dx[8] = {0,0,1,-1,1,1,-1,-1};
int dy[8] = {1,-1,0,0,1,-1,1,-1};

int main(){
    int h, w;
    cin >> h >> w;

    int si, sj, gi, gj;
    char mat[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
            if(mat[i][j] == 's')    si = i, sj = j;
            if(mat[i][j] == 'g')    gi = i, gj = j;
        }
    }

    bool visit[h][w];
    memset(visit, 0, sizeof(visit));
    queue<pair<int,int>> q;
    q.push({si,sj});
    while(!q.empty()){
        pair<int,int> pos = q.front();  q.pop();
        int i = pos.first, j = pos.second;
        if(visit[i][j]) continue;
        visit[i][j] = true;
        for(int k = 0; k < 4; k++){
            int ni = i+dx[k], nj = j+dy[k];
            if(inRange(ni,0,h)&&inRange(nj,0,w)&&mat[ni][nj]!='#'){
                q.push({ni,nj});
            }
        }
    }

    if(!visit[gi][gj]){
        cout << -1 << endl;
        return 0;
    }
    
    double bias[h*w+1];
    bias[0] = 1;
    for(int i = 1; i < h*w+1; i++)    bias[i] = bias[i-1]*0.99;

    double l = 0, r = 10.0;
    while(r-l > 1e-12){
        double mid = (l+r)/2;
        
        memset(visit, 0, sizeof(visit));

        queue<pair<int,pair<int,int>>> s;
        s.push({0,{si,sj}});

        bool valid = false;
        while(!valid && !s.empty()){
            auto p = s.front();   s.pop();
            int t = p.first, i = p.second.first, j = p.second.second;
            if(visit[i][j]) continue;
            visit[i][j] = true;
            for(int k = 0; k < 4; k++){
                int ni = i+dx[k], nj = j+dy[k];
                if(inRange(ni,0,h)&&inRange(nj,0,w)&&!visit[ni][nj]){
                    if(mat[ni][nj] == 'g'){
                        valid = true;
                        break;
                    }
                    if(inRange(mat[ni][nj], '1', ':')){
                        if(bias[t+1]*(mat[ni][nj]-'0') > mid){
                            s.push({t+1, {ni,nj}});
                        }
                    }
                }
            }
        }

        if(valid)   l = mid;
        else        r = mid;
    }

    cout << fixed << setprecision(12) << l << endl;

    return 0;
}