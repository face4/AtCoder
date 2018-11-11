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

    char red[h][w], blue[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(i%2 == 0){
                red[i][j] = (j == w-1) ? '.' : '#';
                blue[i][j] = '.';
            }else{
                blue[i][j] = (j == 0) ? '.' : '#';
                red[i][j] = '.';
            }
            if(mat[i][j] == '#'){
                red[i][j] = blue[i][j] = '#';
            }
        }
    }

    for(int i = 0; i < h; i++)  red[i][0] = blue[i][w-1] = '#';

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << red[i][j];
        }
        cout << endl;
    }
    
    cout << endl;
    
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << blue[i][j];
        }
        cout << endl;
    }

    return 0;
}