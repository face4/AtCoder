// O(WH)
#include<iostream>
using namespace std;
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

    char ans[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            ans[i][j] = '.';
            if(mat[i][j] == '.'){
                continue;
            }
            bool valid = true;
            for(int k = 0; k < 8; k++){
                int ni = i + dx[k], nj = j + dy[k];
                if(inRange(ni,0,h) && inRange(nj,0,w) && mat[ni][nj] == '.'){
                    valid = false;
                }
            }
            if(valid)   ans[i][j] = '#';
        }
    }

    char check[h][w];
    for(int i = 0; i < h; i++)  for(int j = 0; j < w; j++)  check[i][j] = '.';

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(ans[i][j] == '.')    continue;
            check[i][j] = '#';
            for(int k = 0; k < 8; k++){
                int ni = i + dx[k], nj = j+dy[k];
                if(inRange(ni,0,h) && inRange(nj,0,w))  check[ni][nj] = '#';
            }
        }
    }

    bool judge = true;
    for(int i = 0; i < h; i++)  for(int j = 0; j < w; j++)  judge &= (check[i][j] == mat[i][j]);

    if(judge){
        cout << "possible" << endl;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cout << ans[i][j];
            }
            cout << endl;
        }
    }else{
        cout << "impossible" << endl;
    }

    return 0;
}