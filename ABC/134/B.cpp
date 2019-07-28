#include<iostream>
using namespace std;

int main(){
    int n, d;
    cin >> n >> d;
    d = 2*d+1;
    cout << (n+d-1)/d << endl;
    return 0;
}