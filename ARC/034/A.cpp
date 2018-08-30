#include<iostream>
#include<iomanip>
using namespace std;

double calc(int a, int b, int c, int d, int e){
    return a+b+c+d + e*110/900.0;
}

int main(){
    int n, a, b, c, d, e;
    double ans = 0;

    cin >> n;
    while(n-- > 0){
        cin >> a >> b >> c >> d >> e;
        ans = max(ans, calc(a,b,c,d,e));
    }

    cout << fixed << setprecision(7) << ans << endl;
    return 0;
}