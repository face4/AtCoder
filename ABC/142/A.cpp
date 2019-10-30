#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin >> n;
    int odd = n/2 + n%2;
    cout << fixed << setprecision(12) << (double)odd/n << endl;
    return 0;
}