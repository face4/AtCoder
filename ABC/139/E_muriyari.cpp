#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int v[1000][1000];
int memo[1000][1000];
int now[1000];
bool used[1000];

// TLEしそう. 
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            scanf("%d", &v[i][j]);
            v[i][j]--;
            memo[i][v[i][j]] = j;
        }
    }
    int cnt = 0, fin = 0;
    while(fin != n){
        cnt++;
        bool update = false;
        memset(used, 0, sizeof(used));
        for(int i = 0; i < n; i++){
            if(used[i] || now[i] == n-1)   continue;
            int enemy = v[i][now[i]];
            if(memo[enemy][i] == now[enemy]){
                update = true;
                used[i] = used[enemy] = true;
            }
        }
        for(int i = 0; i < n; i++){
            if(!used[i])    continue;
            now[i]++;
            if(now[i] == n-1)   fin++;
        }
        if(!update){
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n", cnt);
    return 0;
}