#include<iostream>
#include<vector>
using namespace std;

const int N = 300000;
const int M = 100000;

int before[N+1] = {};
int after[N+1] = {};
int accum[N+1] = {};
int s[M], t[M];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++){
        scanf("%d %d", s+i, t+i);
        before[s[i]]++;
        after[t[i]]++;
    }

    int now = 0;
    for(int i = 1; i <= n; i++){
        now += before[i];
        if(now <= 1)    accum[i] = 1;
        now -= after[i];
    }

    for(int i = 1; i <= n; i++) accum[i] += accum[i-1];

    vector<int> res;
    for(int i = 0; i < m; i++){
        if(accum[t[i]] - accum[s[i]-1] == 0)    res.push_back(i+1);
    }

    printf("%d\n", res.size());
    for(int x : res)    printf("%d\n", x);

    return 0;
}