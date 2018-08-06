#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    double ans = 6.0 * (k-1) * (n-k);
    ans += 3.0 * (n-1);
    ans += 1;
    ans /= n;
    ans /= n;
    ans /= n;

    cout << fixed << setprecision(10) << ans << endl; 
    return 0;
}