#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin >> n;
    double ans = 0;
    for(int i = 0; i < n; i++){
        double x;   cin >> x;
        ans += 1/x;
    }
    cout << fixed << setprecision(12) << 1/ans << endl;
    return 0;
}