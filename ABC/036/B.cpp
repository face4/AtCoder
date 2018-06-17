#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    char mat[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = n-1; j >= 0; j--){
            cout << mat[j][i];
        }
        cout << endl;
    }

    return 0;
}