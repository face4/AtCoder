#include<iostream>
using namespace std;

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    cout << b*min(n,5) + a*max(n-5,0) << endl;
    return 0;
}