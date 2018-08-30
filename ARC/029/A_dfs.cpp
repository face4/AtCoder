#include<iostream>
#include<numeric>
using namespace std;

int n, t[4] = {}, sum, ans;

void dfs(int i, int accum){
    if(i == n){
        ans = min(ans, max(accum, sum-accum));
        return;
    }

    dfs(i+1, accum+t[i]);
    dfs(i+1, accum);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)  cin >> t[i];
    ans = sum = accumulate(t, t+n, 0);
    dfs(0,0);
    cout << ans << endl;
    return 0;
}