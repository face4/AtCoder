#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>

using namespace std;

const double PI = 2 * acos(0.0);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    double R[n];
    for(int i = 0; i < n; i++)  cin >> R[i];
    sort(R, R+n);

    reverse(R, R+n);
    
    double ans = 0;
    for(int i = 0; i < n; i++){
        if(i%2){
            ans -= R[i]*R[i]*PI;
        }else{
            ans += R[i]*R[i]*PI;
        }
    }

    cout << fixed << setprecision(6) << ans << endl;
    return 0;
}