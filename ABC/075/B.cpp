#include<iostream>
using namespace std;

int dx[8] = {0,0,-1,-1,-1,1,1,1};
int dy[8] = {1,-1,-1,0,1,-1,0,1};

int main(){
    int h, w;
    cin >> h >> w;

    char mat[h][w];
    int bomb[h+2][w+2] = {};
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
            if(mat[i][j] == '#'){
                for(int k = 0; k < 8; k++){
                    bomb[i+dx[k]+1][j+dy[k]+1]++;
                }
            }
        }
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(mat[i][j] == '#')    cout << "#";
            else                    cout << bomb[i+1][j+1];
        }
        cout << endl;
    }

    return 0;
}