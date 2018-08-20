#include<iostream>
using namespace std;

int sum[501][501] = {};

// 二次元累積和によるO(N^2)解法

int main(){ 
    int n, m, Q;
    scanf("%d %d %d\n", &n, &m, &Q);

    int l, r, p, q;
    for(int i = 0; i < m; i++){
        scanf("%d %d\n", &l, &r);
        sum[l][r]++;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            sum[i][j] = sum[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
    }

    for(int i = 0; i < Q; i++){
        scanf("%d %d\n", &p, &q);
        printf("%d\n", sum[q][q] - sum[p-1][q] - sum[q][p-1] + sum[p-1][p-1]);
    }

    return 0;
}