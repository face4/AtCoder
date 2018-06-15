#include<iostream>
using namespace std;

int main(){
    char map[4][4], c;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cin >> c;
            map[i][j] = c;
        }
    }

    for(int i = 3; i >= 0; i--){
        for(int j = 3; j >= 0; j--){
            if(j!=3)    cout << " ";
            cout << map[i][j];
        }
        cout << endl;
    }

    return 0;
}