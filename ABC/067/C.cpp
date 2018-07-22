#include<iostream>
#include<climits>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;

    ll sum[n+1];
    sum[0] = 0;

    for(int i = 1; i <= n; i++){
        cin >> sum[i];
        sum[i] += sum[i-1];
    }

    ll ans = LLONG_MAX;
    for(int i = 1; i < n; i++){
        ll a = sum[i] - sum[0];
        ll b = sum[n] - sum[i];
        ans = min(ans, abs(a-b));
    }

    cout << ans << endl;

    return 0;
}