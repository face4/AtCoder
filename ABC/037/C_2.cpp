#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    int n, k;
    cin >> n >> k;

    ll sum[n+1];
    sum[0] = 0ll;

    for(int i = 0; i < n; i++){
        cin >> sum[i+1];
        sum[i+1] += sum[i];
    }

    ll ans = 0;
    for(int i = k; i <= n; i++) ans += sum[i] - sum[i-k];
    cout << ans << endl;

    return 0;
}