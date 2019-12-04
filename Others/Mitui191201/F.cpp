// ?
#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    
    ll ax = t1*a1+t2*a2;
    ll bx = t1*b1+t2*b2;
    if(ax==bx){
        cout << "infinity" << endl;
        return 0;
    }

    if(ax > bx){
        swap(a1, b1);
        swap(a2, b2);
        swap(ax, bx);
    }

    if(a1 < b1){
        cout << 0 << endl;
        return 0;
    }

    ll tmpa = t1*a1-t1*b1;
    ll tmpb = t2*b2-t2*a2;

    ll ans = 1;
    ll tmp = tmpb-tmpa;

    ans += (tmpa-tmp+tmp-1)/tmp*2;
    ans += (tmpa-tmp)%tmp==0;
    
    cout << ans << endl;
    
    return 0;
}