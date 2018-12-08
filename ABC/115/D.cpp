#include<iostream>
using namespace std;

typedef long long ll;

ll dfs(int n, ll x){
    if(n == 0)  return 1;
    if(x <= 1)  return 0;

    ll len = (1ll<<(n+2))-3;
    ll center = len/2+1;
    
    // 区間を完全に覆ってしまった時点で枝刈りをしないとdfsの呼び出しが指数的に爆発して死ぬ
    if(x == len)    return 1 + 2ll*dfs(n-1, center-2);
    
    if(x < center)          return dfs(n-1, x-1);
    else if(x == center)    return 1 + dfs(n-1, center-2);
    else if(x > center)     return 1 + dfs(n-1, center-2) + dfs(n-1, x-1-center+1);
}

int main(){
    int n;
    ll x;
    cin >> n >> x;
    cout << dfs(n, x) << endl;
    return 0;
}
