#include<iostream>
using namespace std;

#define N 2000
char mat[N+1][N+1];
int l[N+1][N+1] = {}, r[N+1][N+1] = {}, u[N+1][N+1] = {}, d[N+1][N+1] = {};

int main(){
    int h, w;
    cin >> h >> w;

    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            cin >> mat[i][j];
        }
    }

    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            if(mat[i][j] == '#')    continue;
            u[i][j] = u[i-1][j] + 1;
        }
    }

    for(int i = h; i >= 1; i--){
        for(int j = 1; j <= w; j++){
            if(mat[i][j] == '#')    continue;
            d[i][j] = d[i+1][j] + 1;
        }
    }

    for(int j = 1; j <= w; j++){
        for(int i = 1; i <= h; i++){
            if(mat[i][j] == '#')    continue;
            l[i][j] = l[i][j-1] + 1;
        }
    }

    for(int j = w; j >= 1; j--){
        for(int i = 1; i <= h; i++){
            if(mat[i][j] == '#')    continue;
            r[i][j] = r[i][j+1] + 1;
        }
    }

    long long ans = 0;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            if(mat[i][j] == '#')    continue;
            ans += (l[i][j]-1 + r[i][j]-1) * (u[i][j]-1 + d[i][j]-1);
        }
    }

    cout << ans << endl;

    return 0;
}
