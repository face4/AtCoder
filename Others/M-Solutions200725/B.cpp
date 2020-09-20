#include<iostream>
using namespace std;

bool f = false;

void dfs(int a, int b, int c, int k){
    if(a > b && b > c){
        f = true;
        return;
    }
    if(k == 0)  return;
    dfs(2*a, b, c, k-1);
    dfs(a, 2*b, c, k-1);
    dfs(a, b, 2*c, k-1);
}

int main(){
    int a[3];
    cin >> a[2] >> a[1] >> a[0];
    int k;
    cin >> k;
    dfs(a[0], a[1], a[2], k);
    cout << (f ? "Yes" : "No") << endl;
    return 0;
}