#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    double a, b, x, y;
    cin >> a >> b >> x >> y;
    cout << fixed << setprecision(12) << a+(x-a)*b/(b+y) << endl;
    return 0;
}