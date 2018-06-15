#include<iostream>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    cout << 3-(a>b)-(a>c) << endl;
    cout << 3-(b>a)-(b>c) << endl;
    cout << 3-(c>b)-(c>a) << endl;
    
    return 0;
}