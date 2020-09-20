#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    ll x = 1e18;
    ll ret = 1;
    bool zero = false;
    bool ng = false;
    while(n--){
        ll a;
        cin >> a;
        zero |= a==0;
        if(ng || x/ret < a){
            ng = true;
            continue;
        }
        ret *= a;
    }
    if(zero)        cout << 0 << endl;
    else if(ng)     cout << -1 << endl;
    else            cout << ret << endl;
    return 0;
}