#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        ans += (i+1)*(n-i);
    }
    for(int i = 0; i < n-1; i++){
        ll u, v;
        cin >> u >> v;
        if(u > v)   swap(u, v);
        ans -= u*(n-v+1);
    }
    cout << ans << endl;
    return 0;
}