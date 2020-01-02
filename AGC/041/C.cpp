#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n == 2){
        cout << -1 << endl;
        return 0;
    }
    if(n == 3){
        cout << "a..\na..\n.aa" << endl;
        return 0;
    }
    char mat[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            mat[i][j] = '.';
        }
    }
    char ord[4][4] = { 
        {'a', 'a', 'c', 'd'}, 
        {'b', 'b', 'c', 'd'}, 
        {'e', 'f', 'g', 'g'}, 
        {'e', 'f', 'h', 'h'},
    };
    int i = 0;
    while(i+7 < n){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                mat[i+j][i+k] = ord[j][k];
            }
        }
        i += 4;
    }
    if(i+7 == n){
        string s[7] = {"aabbaa.", "bb.cc.a", "..a..ba", "..a..bc", "aa.aa.c", "..a..ab", "..a..ab"};
        for(int j = 0; j < 7; j++){
            for(int k = 0; k < 7; k++){
                mat[i+j][i+k] = s[j][k];
            }
        }
    }else if(i+6 == n){
        string s[6] = {"abcc..", "abdd..", "..efgg", "..efhh", "ii..jk", "ll..jk"};
        for(int j = 0; j < 6; j++){
            for(int k = 0; k < 6; k++){
                mat[i+j][i+k] = s[j][k];
            }
        }
    }else if(i+5 == n){
        string s[5] = {"aabbc", "dee.c", "d..fg", "h..fg", "hiijj"};
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 5; k++){
                mat[i+j][i+k] = s[j][k];
            }
        }
    }else if(i+4 == n){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                mat[i+j][i+k] = ord[j][k];
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << mat[i][j];
        }
        cout << endl;
    }
    return 0;
}