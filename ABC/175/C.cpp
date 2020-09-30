#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll x, k, d;
    cin >> x >> k >> d;
    if(x < 0)   x = -x;
    if(k < x/d){
        cout << x-d*k << endl;
        return 0;
    }else{
        k -= x/d;
        x %= d;
        cout << (k%2==1 ? d-x : x) << endl;
    }
    return 0;
}