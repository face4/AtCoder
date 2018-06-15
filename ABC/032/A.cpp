#include<iostream>
using namespace std;

int main(){
    int a, b, n;
    cin >> a >> b >> n;

    while(n%a || n%b)   n++;

    cout << n << endl;
    return 0;
}