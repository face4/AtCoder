#include<iostream>
using namespace std;

int main(){
    int x, a, b;
    cin >> x >> a >> b;
    x -= a;
    x -= x/b*b;
    cout << x << endl;
    return 0;
}