#include<iostream>
using namespace std;

int main(){
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    a = max(a, c);
    b = min(b, d);
    cout << (a<=b ? "Yes" : "No") << endl;
    return 0;
}