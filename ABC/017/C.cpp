// 取らない宝石を固定して考える
#include<iostream>
using namespace std;

int main(){
    int n, m, l, r, s, sum = 0;
    cin >> n >> m;

    int a[100001] = {};
    while(n-- > 0){
        cin >> l >> r >> s;
        a[l-1] += s, a[r] -= s;
        sum += s;
    }

    int ans = sum - a[0];
    for(int i = 1; i < m; i++){
        a[i] += a[i-1];
        ans = max(ans, sum-a[i]);
    }

    cout << ans << endl;

    return 0;
}