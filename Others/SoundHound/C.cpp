#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
    int n, m, d;
    cin >> n >> m >> d;

    int pairs = n-d;
    
    double ans = (double)(pairs) * 2 * (m-1) / n / n;
    if(d == 0)  ans /= 2.0;
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}