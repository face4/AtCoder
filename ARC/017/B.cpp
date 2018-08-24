#include<iostream>
using namespace std;

int main(){
    int n, k;
    scanf("%d %d\n", &n, &k);

    int a[n], b[n];

    for(int i = 0; i < n; i++){
        scanf("%d\n", a+i);
    }

    b[0] = 1;
    for(int i = 1; i < n; i++){
        b[i] = a[i-1] < a[i] ? b[i-1] + 1 : 1;
    }

    int cnt = 0;
    for(int i = k-1; i < n; i++)    if(b[i] >= k)   cnt++;

    printf("%d\n", cnt);
    
    return 0;
}