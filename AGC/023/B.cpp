#include<iostream>
using namespace std;

// 解説を読んだ
int main(){
    int n;
    cin >> n;
    char mat[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }
    int ans = 0;
    for(int d = 0; d < n; d++){
        bool ok = true;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ok &= mat[(i+d)%n][j] == mat[(j+d)%n][i];
                // printf("(%d,%d) -> (%d,%d)\n", (i+d)%n, j, (j+d)%n, i);
            }
        }
        ans += n * ok;
    }
    cout << ans << endl;
    return 0;
}