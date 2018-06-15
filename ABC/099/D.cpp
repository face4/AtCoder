#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;
typedef long long ll;

int main(){
    int n, c;
    cin >> n >> c;

    int M[n][n];
    int D[c][c];

    int x;
    for(int i = 0; i < c; i++){
        for(int j = 0; j < c; j++){
            cin >> x;
            D[i][j] = x;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> x;
            M[i][j] = x;
        }
    }

    int count[3][c];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < c; j++){
            count[i][j] = 0;
        }
    }

    int now;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            now = (i+1+j+1)%3;
            count[now][M[i][j]-1]++;
        }
    }

    // for(int i = 0; i < 3; i++){
    //     for(int j = 0; j < c; j++){
    //         cout << count[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    ll ans = LLONG_MAX;
    for(int i = 0; i < c-2; i++){
        for(int j = i+1; j < c-1; j++){
            for(int k = j+1; k < c; k++){
                // 配色をi,j,kにする
                int colors[3] = {i, j, k};

                // y を xに塗り替える
                do{
                    ll can = 0;
                    for(int x = 0; x < 3; x++){
                        for(int y = 0; y < c; y++){
                            can += (ll)D[y][colors[x]] * (ll)count[x][y];
                        }
                    }
                    ans = min(can, ans);
                }while(next_permutation(colors, colors+3));
            }
        }
    }

    cout << ans << endl;
    return 0;
}