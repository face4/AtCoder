#include<iostream>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    char mat[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(j+1 < w && mat[i][j]=='.'&&mat[i][j+1]=='.') ans++;
            if(i+1 < h && mat[i][j]=='.'&&mat[i+1][j]=='.') ans++;
        }
    }
    cout << ans << endl;
    return 0;
}