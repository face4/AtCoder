#include<iostream>
using namespace std;

bool win[100][100] = {};

int main(){
    int h, w;
    cin >> h >> w;

    char mat[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
        }
    }

    for(int i = h-1; i >= 0; i--){
        for(int j = w-1; j >= 0; j--){
            win[i][j] = 
                (mat[i][j] != '#') && 
                ( (i != h-1 && mat[i+1][j] == '.' && !win[i+1][j]) || 
                  (j != w-1 && mat[i][j+1] == '.' && !win[i][j+1]) || 
                  (i != h-1 && j != w-1 && mat[i+1][j+1] == '.' && !win[i+1][j+1]) );
        }
    }

    cout << (win[0][0] ? "First" : "Second") << endl;

    return 0;
}