#include<iostream>
using namespace std;

int main(){
    int mat[4][4];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cin >> mat[i][j];
        }
    }

    bool judge = false;
    for(int i = 0; !judge && i < 4; i++){
        for(int j = 0; !judge && j < 4; j++){
            if(i != 3)  judge = mat[i][j]==mat[i+1][j];
            if(judge)   continue;
            if(j != 3)  judge = mat[i][j]==mat[i][j+1];
        }
    }

    if(judge)   cout << "CONTINUE" << endl;
    else        cout << "GAMEOVER" << endl;

    return 0;
}