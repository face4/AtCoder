#include<iostream>
using namespace std;

int main(){
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    a = a*60+b, c = c*60+d;
    cout << c-a-e << endl;
    return 0;
}