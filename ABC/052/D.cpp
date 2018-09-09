#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    ll n, a, b;
    cin >> n >> a >> b;

    ll ans = 0, before, now;
    cin >> before;
    for(int i = 1; i < n; i++){
        cin >> now;
        ans += min(b, (now-before)*a);
        before = now;
    }

    cout << ans << endl;

    return 0;
}