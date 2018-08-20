#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    double n;
    cin >> n;
    cout << fixed << setprecision(7) << (9.0 / 5.0 * n) + 32.0 << endl;
    return 0;
}