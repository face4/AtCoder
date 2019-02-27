#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin >> n;
    double ans = 0;
    while(n-- > 0){
        double x;
        string s;
        cin >> x >> s;
        if(s == "JPY")  ans += x;
        else            ans += 380000.0*x;
    }
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}