#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    int n, k;
    cin >> n >> k;

    ll a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];

    ll ans = 0;
    for(int i = 0; i < k; i++) ans += a[i];

    ll tmp = ans;
    for(int i = k; i < n; i++){
        tmp += a[i];
        tmp -= a[i-k];
        ans += tmp;
    } 

    cout << ans << endl;

    return 0;
}