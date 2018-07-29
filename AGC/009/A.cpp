#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;

    ll a[n], b[n];
    for(int i = 0; i < n; i++)  cin >> a[i] >> b[i];

    ll ans = 0;
    for(int i = n-1; i >= 0; i--){
        a[i] += ans;
        ans += (a[i]+b[i]-1)/b[i]*b[i] - a[i];
    }

    cout << ans << endl;

    return 0;
}