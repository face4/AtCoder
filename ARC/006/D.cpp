#include<iostream>
#include<queue>
using namespace std;

#define inRange(x,a,b) (a <= x && x < b)
int di[8] = {0,0,1,-1,1,1,-1,-1};
int dj[8] = {1,-1,0,0,1,-1,1,-1};

int main(){
    int h, w;
    cin >> h >> w;
    char mat[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
        }
    }
    queue<pair<int,int>> q;
    mat[0][0] = 'x';
    q.push({0, 0});
    while(!q.empty()){
        pair<int,int> p = q.front();    q.pop();
        int i = p.first, j = p.second;
        for(int k = 0; k < 4; k++){
            int ni = i+di[k], nj = j+dj[k];
            if(inRange(ni,0,h) && inRange(nj,0,w) && mat[ni][nj] == '.'){
                mat[ni][nj] = 'x';
                q.push({ni, nj});
            }
        }
    }

    int a = 0, b = 0, c = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(mat[i][j] != 'o')    continue;
            int hole = 0;
            mat[i][j] = 'x';
            q.push({i, j});
            while(!q.empty()){
                pair<int,int> p = q.front();    q.pop();
                int pi = p.first, pj = p.second;
                for(int k = 0; k < 8; k++){
                    int ni = pi+di[k], nj = pj+dj[k];
                    if(!inRange(ni,0,h)||!inRange(nj,0,w)||mat[ni][nj]=='x')  continue;
                    if(mat[ni][nj] == 'o'){
                        mat[ni][nj] = 'x';
                        q.push({ni,nj});
                    }else if(mat[ni][nj] == '.'){
                        mat[ni][nj] = 'x';
                        hole++;
                        queue<pair<int,int>> qq;
                        qq.push({ni,nj});
                        while(!qq.empty()){
                            pair<int,int> pp = qq.front();  qq.pop();
                            int si = pp.first, sj = pp.second;
                            for(int l = 0; l < 4; l++){
                                int nni = si+di[l], nnj = sj+dj[l];
                                if(inRange(nni,0,h)&&inRange(nnj,0,w)&&mat[nni][nnj]=='.'){
                                    mat[nni][nnj] = 'x';
                                    qq.push({nni, nnj});
                                }
                            }
                        }
                    }
                }
            }
            if(hole == 0)   c++;
            if(hole == 1)   a++;
            if(hole == 2)   b++;
        }
    }
    cout << a << " " << b << " " << c << endl;
    return 0;
}