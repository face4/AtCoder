#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    ll a, b, x;
    cin >> a >> b >> x;
    
    ll low, high;
    if(a % x == 0) low = a;
    else           low = (a/x+1ll) * x;
    
    high = (b/x) * x;  

    cout << (high-low)/x + 1ll << endl;

    return 0;
}