#include<iostream>
using namespace std;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int lower = max(a,c);
    int upper = min(b,d);
    cout << max(0, upper-lower) << endl;
    return 0;
}