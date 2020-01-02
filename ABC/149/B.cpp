#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll a, b, k;
    cin >> a >> b >> k;
    ll tmp = min(a,k);
    a -= tmp;
    if(k-tmp > 0)   b = max(0, b-(k-tmp));
    cout << a << " " << b << endl;
    return 0;
}