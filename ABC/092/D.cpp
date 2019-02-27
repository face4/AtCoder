#include<iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    char mat[100][100];
    string s = "#.";
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            mat[i][j] = s[i/50];
        }
    }
    a--, b--;
    for(int i = 0; i < 50; i++){
        for(int j = 1 + i%2; a > 0 && j < 100; j += 3){
            mat[i][j] = '.';
            a--;
        }
    }
    for(int i = 51; i < 100; i++){
        for(int j = 1 + i%2; b > 0 && j < 100; j += 3){
            mat[i][j] = '#';
            b--;
        }
    }
    cout << 100 << " " << 100 << endl;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            cout << mat[i][j];
        }
        cout << endl;
    }
    return 0;
}