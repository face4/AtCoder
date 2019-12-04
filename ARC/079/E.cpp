#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];
    ll ans = 0;
    while(true){
        ll sum = 0;
        ll b[n];
        for(int i = 0; i < n; i++){
            sum += a[i]/n;
            b[i] = a[i]/n;
            a[i] %= n;
        }
        if(sum == 0)    break;
        for(int i = 0; i < n; i++){
            a[i] += sum-b[i];
        }
        ans += sum;
    }
    cout << ans << endl;
    return 0;
}