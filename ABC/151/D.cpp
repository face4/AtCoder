#include<iostream>
#include<queue>
#include<vector>
using namespace std;

#define inRange(x,a,b) (a <= x && x < b)
int di[8] = {0,0,1,-1,1,1,-1,-1};
int dj[8] = {1,-1,0,0,1,-1,1,-1};

int main(){
    int h, w;
    cin >> h >> w;
    char mat[h][w];
    for(int i = 0; i < h*w; i++)    cin >> mat[i/w][i%w];
    int ret = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(mat[i][j] == '#')    continue;
            vector<vector<int>> d(h, vector<int>(w, 1<<30));
            queue<int> q;
            d[i][j] = 0;
            q.push(i*w+j);
            while(!q.empty()){
                int x = q.front();  q.pop();
                int si = x/w, sj = x%w;
                ret = max(ret, d[si][sj]);
                for(int k = 0; k < 4; k++){
                    int ni = si+di[k], nj = sj+dj[k];
                    if(inRange(ni,0,h)&&inRange(nj,0,w)&&mat[ni][nj]=='.'&&d[ni][nj]>d[si][sj]+1){
                        d[ni][nj] = d[si][sj]+1;
                        q.push(ni*w+nj);
                    }
                }
            }
        }
    }
    cout << ret << endl;
    return 0;
}