#include<iostream>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int a[100001] = {}, b[100001] = {}, c[100001] = {};
ll d[100001] = {};

int main(){
    int n;
    cin >> n;

    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        a[x]++, b[x]++, c[x]++;
    }

    for(int i = 1; i <= 100000; i++)    b[i] += b[i-1];
    for(int i = 99999; i >= 0; i--)     c[i] += c[i+1];
    for(int i = 50000; i >= 0; i--)     d[i] = (a[i] * c[2*i]) % mod;
    for(int i = 99999; i >= 0; i--)     d[i] = (d[i] + d[i+1]) % mod;

    ll ans = 0;
    for(int i = 2; i <= 50000; i++){
        ans = (ans + (((ll)b[i/2]*a[i])%mod * d[2*i])%mod)%mod;
    }

    cout << ans << endl;

    return 0;
}