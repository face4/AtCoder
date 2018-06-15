#include<iostream>
using namespace std;

int main(){
    int a, b, c, k, s, t;
    cin >> a >> b >> c >> k >> s >> t;

    int res = a*s + b*t;
    if(s+t >= k)    res -= c*(s+t);

    cout << res << endl;
    return 0;
}