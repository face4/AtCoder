#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    char mat[n][n];
    for(int i = 0; i < n*n; i++)    cin >> mat[i/n][i%n];
    int ret = 0;
    for(int i = 0; i < n; i++){
        int rig;
        for(rig = n-1; rig >= 0; rig--){
            if(mat[i][rig] == '.')  break;
        }
        if(rig == -1)   continue;
        ret++;
        for(int j = rig; j >= 0; j--)   mat[i][j] = 'o';
        if(i == n-1)    continue;
        for(int j = rig; j < n; j++)    mat[i+1][j] = 'o';
    }
    cout << ret << endl;
    return 0;
}