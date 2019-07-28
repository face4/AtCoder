#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;

int main(){
    ll s;
    cin >> s;
    ll a = sqrt(s);
    if(a*a < s) a++;
    ll d = a;
    if(d*d-s > 1e9) d--;
    ll b = a*d-s;
    printf("0 0 %d 1 %d %d\n", a, b, d);
    return 0;
}
