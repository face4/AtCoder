// 2*K*(R-K+1)*(C-K+1)
#include<iostream>
using namespace std;

int u[500][500] = {}, d[500][500] = {};

int main(){
    int r, c, k;
    cin >> r >> c >> k;
    char mat[r][c];
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> mat[i][j];
        }
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(mat[i][j] == 'o'){
                u[i][j] = (i != 0 ? u[i-1][j] : 0) + 1;
            }
            if(mat[r-1-i][j] == 'o'){
                d[r-1-i][j] = (i != 0 ? d[r-1-i+1][j] : 0) + 1;
            }
        }
    }
    int ans = 0;
    for(int i = k-1; i < r-k+1; i++){
        for(int j = k-1; j < c-k+1; j++){
            bool judge = true;
            for(int x = 0; x < k; x++){
                judge &= (u[i][j-x] >= k-x) && (d[i][j-x] >= k-x);
                judge &= (u[i][j+x] >= k-x) && (d[i][j+x] >= k-x);
            }
            ans += judge;
        }
    }
    cout << ans << endl;
    return 0;
}