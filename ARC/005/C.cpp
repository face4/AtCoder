// O(WH)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define inRange(x,a,b) (a <= x && x < b)
int dx[8] = {0,0,1,-1,1,1,-1,-1};
int dy[8] = {1,-1,0,0,1,-1,1,-1};

int main(){
    int h, w;
    cin >> h >> w;

    int si, sj, gi, gj;
    vector<vector<char>> mat(h, vector<char>(w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
            if(mat[i][j] == 's')    si = i, sj = j;
            if(mat[i][j] == 'g')    gi = i, gj = j;
        }
    }

    for(int t = 0; t < 2; t++){
        vector<vector<bool>> flag(h, vector<bool>(w, 0));
        vector<vector<bool>> visit(h, vector<bool>(w, 0));
        
        queue<pair<int,int>> s;
        s.push({si,sj});
        
        while(!s.empty()){
            pair<int,int> now = s.front();  s.pop();
            int i = now.first, j = now.second;
            if(visit[i][j]) continue;
            visit[i][j] = true;
            for(int k = 0; k < 4; k++){
                int di = i + dx[k], dj = j + dy[k];
                if(inRange(di, 0, h) && inRange(dj, 0, w) && !visit[di][dj]){
                    if(mat[di][dj] == '.')  s.push({di,dj});
                    if(mat[di][dj] == '#')  flag[di][dj] = true;
                }
            }
        }

        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(flag[i][j])  mat[i][j] = '.';
            }
        }
    }

    vector<vector<bool>> visit(h, vector<bool>(w, 0));
    queue<pair<int,int>> s;
    s.push({si,sj});

    while(!s.empty()){
        pair<int,int> now = s.front();  s.pop();
        int i = now.first, j = now.second;
        if(visit[i][j]) continue;
        visit[i][j] = true;
        for(int k = 0; k < 4; k++){
            int di = i + dx[k], dj = j + dy[k];
            if(inRange(di, 0, h) && inRange(dj, 0, w) && !visit[di][dj] && mat[di][dj] != '#'){
                s.push({di,dj});
            }
        }
    }

    cout << (visit[gi][gj] ? "YES" : "NO") << endl;

    return 0;
}