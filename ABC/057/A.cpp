#include<iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;

    cout << (a+b)%24 << endl;
    //cout << (a+b>23 ? (a+b-24) : (a+b)) << endl;
    return 0;
}