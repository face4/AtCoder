#include<iostream>
#include<cmath>
#include<numeric>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin >> n;
    double x[n];
    for(int i = 0; i < n; i++)  cin >> x[i];
    double a = 0, b = 0, c = 0;
    for(int i = 0; i < n; i++){
        a += abs(x[i]);
        b += x[i]*x[i];
        c = max(c, abs(x[i]));
    }
    b = sqrt(b);
    cout << fixed << setprecision(12) << a << endl << b << endl << c << endl;
    return 0;
}