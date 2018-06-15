#include<iostream>
using namespace std;

int main(){
    int n, t;
    scanf("%d %d" , &n, &t);
    int before, now, ans = 0;
    scanf("%d", &before);

    for(int i = 1; i < n; i++){
        scanf("%d", &now);
        ans += min(now-before, t);
        before = now;
    }

    printf("%d\n", ans+t);
    return 0;
}