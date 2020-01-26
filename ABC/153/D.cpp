#include<iostream>
using namespace std;
typedef long long ll;

ll f(ll x){
    if(x == 0)  return 0;
    return 1 + 2 * f(x/2);
}

int main(){
    ll h;
    cin >> h;
    cout << f(h) << endl;
    return 0;
}