#include<iostream>
using namespace std;

int tako[51][51] = {};

int take(int a, int b, int c, int d){
    return tako[c][d] - tako[c][b-1] - tako[a-1][d] + tako[a-1][b-1];
}

int main(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> tako[i][j];
            tako[i][j] += tako[i-1][j] + tako[i][j-1] - tako[i-1][j-1];
        }
    }

    // 事前に計算, O(n^4 + n^2)
    int ans[2501] = {};
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = i; k <= n; k++){
                for(int l = j; l <= n; l++){
                    int num = (l-j+1)*(k-i+1);
                    ans[num] = max(ans[num], take(i,j,k,l));
                }
            }
        }
    }
    for(int i = 1; i <= 2500; i++)  ans[i] = max(ans[i], ans[i-1]);

    int q;
    cin >> q;

    int p;
    for(int i = 0; i < q; i++){
        cin >> p;
        cout << ans[p] << endl;
    }

    return 0;
}