#include<iostream>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;

    int cnt = 0;
    char x;
    for(int i = 0; i < w*h; i++){
        cin >> x;
        if(x == '#') cnt++;
    }

    if(cnt == h+w-1)    cout << "Possible" << endl;
    else                cout << "Impossible" << endl;
/*
    char mat[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
        }
    }

    int posi = 0, posj = 0;
    bool proceed = true;
    while(proceed && (posi != h-1 || posj != w-1)){
        proceed = false;

        while(posj < w-1 && mat[posi][posj+1] == '#'){
            proceed = true;
            mat[posi][posj] = '.';
            posj++;
        }

        while(posi < h-1 && mat[posi+1][posj] == '#'){
            proceed = true;
            mat[posi][posj] = '.';
            posi++;
        }

    }

    if(posi != h-1 || posj != w-1){
        cout << "Impossible" << endl;
    }else{
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(i+j == 0 || i+j == h+w-2)    continue;
                if(mat[i][j] == '#'){
                    cout << "Impossible" << endl;
                    return 0;
                }
            }
        }

        cout << "Possible" << endl;
    }
*/
    return 0;
}