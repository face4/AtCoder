#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<double> p(3001, 0);
    cin >> p[1];
    p[0] = 1-p[1];

    double x;
    for(int i = 1; i < n; i++){
        cin >> x;
        for(int j = i; j >= 0; j--){
            p[j+1] += p[j]*x;
            p[j] *= (1-x);
        }
    }

    double ans = 0;
    for(int i = n/2+1; i <= n; i++)  ans += p[i];

    cout << fixed << setprecision(12) << ans << endl;

    return 0;
}