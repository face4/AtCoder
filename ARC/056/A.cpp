#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    ll a, b, k, l;
    cin >> a >> b >> k >> l;
    cout << (k/l)*b + min(b, (k%l)*a) << endl;
    return 0;
}