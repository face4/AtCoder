#include<iostream>
#include<vector>
using namespace std;

int l[2000][2000] = {}, r[2000][2000] = {};
int u[2000][2000] = {}, d[2000][2000] = {};

int main(){
    int h, w;
    cin >> h >> w;
    char mat[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
        }
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(mat[i][j] != '.')    continue;
            u[i][j] = (i==0 ? 0 : u[i-1][j]) + 1;
        }
    }
    for(int i = h-1; i >= 0; i--){
        for(int j = 0; j < w; j++){
            if(mat[i][j] != '.')    continue;
            d[i][j] = (i==h-1 ? 0 : d[i+1][j]) + 1;
        }
    }

    for(int j = 0; j < w; j++){
        for(int i = 0; i < h; i++){
            if(mat[i][j] != '.')    continue;
            l[i][j] = (j==0 ? 0 : l[i][j-1]) + 1;
        }
    }
    for(int j = w-1; j >= 0; j--){
        for(int i = 0; i < h; i++){
            if(mat[i][j] != '.')    continue;
            r[i][j] = (j==w-1 ? 0 : r[i][j+1]) + 1;
        }
    }

    int ans = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(mat[i][j] == '#')    continue;
            ans = max(ans, l[i][j]+r[i][j]+d[i][j]+u[i][j]-3);
        }
    }
    cout << ans << endl;
    return 0;
}