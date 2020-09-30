#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << max({a*c, b*d, a*d, b*c}) << endl;
    return 0;
}