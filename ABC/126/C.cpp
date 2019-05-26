#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    double ans = 0;
    for(int i = 1; i <= n; i++){
        double tmp = 1.0;
        int cp = i;
        while(cp < k){
            cp *= 2;
            tmp /= 2.0;
        }
        ans += tmp/n;
    }
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}