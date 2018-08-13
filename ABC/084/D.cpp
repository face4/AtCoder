#include<iostream>
using namespace std;

int main(){
    bool nonprime[100001] = {};
    nonprime[0] = nonprime[1] = true;
    for(int i = 2; i < 100001; i++){
        if(!nonprime[i]){
            for(int j = i+i; j < 100001; j+=i){
                nonprime[j] = true;
            }
        }
    }

    int sum[100001] = {};

    for(int i = 1; i < 100001; i++){
        sum[i] = sum[i-1];
        if(!nonprime[i] && !nonprime[(i+1)/2])  sum[i]++;
    }

    int q;
    scanf("%d\n", &q);

    int l, r;
    for(int i = 0; i < q; i++){
        scanf("%d %d\n", &l, &r);
        int ans = sum[r] - sum[l-1];
        printf("%d\n", ans);
    }

    return 0;
}