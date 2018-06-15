#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    ll a,b,c,k;
    cin >> a >> b >> c >> k;
    if(k%2 == 0)    c = a-b;
    else            c = b-a;

    if(abs(c)>10e18)    cout << "Unfair" << endl;
    else                cout << c << endl;
    return 0;
}