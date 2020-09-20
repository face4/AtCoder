#include<iostream>
using namespace std;

int n, p, m;
char mat[40][40], s[40][40];

int main(){
    cin >> n >> p >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> s[i][j];
        }
    }
    while(m--){
        cout << "UDLR"[m%4] << endl;
    }
    return 0;
}