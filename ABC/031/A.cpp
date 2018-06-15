#include<iostream>
using namespace std;

int main(){
    int a, d;
    cin >> a >> d;

    if(a < d)   cout << (a+1)*d << endl;
    else        cout << (d+1)*a << endl;

    return 0;
}