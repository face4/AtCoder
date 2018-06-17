#include<iostream>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

int main(){
    ll a, b, c;
    cin >> a >> b >> c;
    cout << (((a*b)%mod)*c)%mod << endl;
    return 0;    
}