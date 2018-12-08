#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int digit(ll x){
    int ret = 0;
    while(x > 0)    ret += x%10, x /= 10;
    return ret;
}

int main(){
    ll n;
    cin >> n;

    vector<ll> ans;
    for(ll i = max(0ll, n-9*(int)(to_string(n).length())); i <= n; i++){
        if(digit(i)+i == n) ans.push_back(i);
    }

    cout << ans.size() << endl;
    for(ll val : ans)   cout << val << endl;

    return 0;
}