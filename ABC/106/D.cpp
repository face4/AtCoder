#include<iostream>
using namespace std;

int sum[501][501] = {};

int main(){ 
    int n, m, Q;
    scanf("%d %d %d\n", &n, &m, &Q);

    int l, r, p, q;
    for(int i = 0; i < m; i++){
        scanf("%d %d\n", &l, &r);
        sum[l][r]++;
    }

    for(int i = 0; i <= n; i++){
        for(int j = 1; j <= n; j++){
            sum[i][j] += sum[i][j-1];
        }
    }

    for(int i = 0; i < Q; i++){
        scanf("%d %d\n", &p, &q);
        int ans = 0;
        for(int j = p; j <= q; j++){
            ans += sum[j][q] - sum[j][p-1];
        }
        printf("%d\n", ans);
    }

    return 0;
}