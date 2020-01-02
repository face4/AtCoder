#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    ll ret = 1ll<<60;
    if((b-a)%2 == 0)    ret = (b-a)/2;
    ret = min(ret, (a-1+b-1+1)/2);
    ret = min(ret, (n-b+n-a+1)/2);
    cout << ret << endl;
    return 0;
}