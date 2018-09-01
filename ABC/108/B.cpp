#include<iostream>
using namespace std;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int e = -(d-b) + c;
    int f = c-a + d;
    int g = -(d-b) + a;
    int h = c-a + b;
    cout << e << " " << f << " " << g << " " << h << endl;
    return 0;
}