#include<iostream>
using namespace std;

int main(){
    int mat[3][3] = {};
    int minimum = 101;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> mat[i][j];
            minimum = min(minimum, mat[i][j]);
        }
    }

    int m = max(mat[0][0], max(mat[1][0], mat[2][0]));

    for(int b1 = 0; b1 <= min(100, minimum); b1++){
        int a1 = mat[0][0]-b1;
        int a2 = mat[1][0]-b1;
        int a3 = mat[2][0]-b1;
        if(mat[0][1]-a1 == mat[1][1]-a2 && mat[1][1]-a2 == mat[2][1]-a3 &&
           mat[0][2]-a1 == mat[1][2]-a2 && mat[1][2]-a2 == mat[2][2]-a3){
               cout << "Yes" << endl;
               return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}