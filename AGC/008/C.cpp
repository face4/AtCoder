#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll a, b, c, d, g;
    cin >> a >> b >> g >> c >> d >> g >> g;
    ll ans = (ll)b+a/2*2+c/2*2+d/2*2;
    switch(a%2+c%2+d%2){
        case 3:
            ans += 3;
            break;
        case 2:
            ans += (a%2==0&&a>0)||(c%2==0&&c>0)||(d%2==0&&d>0);
            break;
    }
    cout << ans << endl;
    return 0;
}
