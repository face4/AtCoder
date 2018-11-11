#include<iostream>
#include<climits>
#include<numeric>
using namespace std;
typedef long long ll;

int main(){
    int n, x;
    cin >> n >> x;

    ll a[n], b[n];
    for(int i = 0; i < n; i++) cin >> a[i], b[i] = a[i];

    ll ans = accumulate(b, b+n, 0ll);

    for(int k = 1; k < n; k++){
        ll tmp = (ll)k * x;
        for(int i = 0; i < n; i++){
            b[i] = min(b[i], a[(i+n-k)%n]);
        }
        tmp += accumulate(b, b+n, 0ll);
        ans = min(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}