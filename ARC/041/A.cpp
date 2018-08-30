#include<iostream>
using namespace std;

int main(){
    int x, y, k;
    cin >> x >> y >> k;
    cout << x-max(0,k-y) + min(y,k) << endl;
    return 0;
}