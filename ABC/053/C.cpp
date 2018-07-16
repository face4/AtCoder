#include<iostream>
using namespace std;

int main(){
    long long x;
    cin >> x;
    cout << x/11*2 + (x%11+5)/6 << endl;
    return 0;
}