#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    int a[n+1];
    for(int i = 0; i < n+1; i++)    cin >> a[i];
    ll ans = 0;
    for(int i = 0; i < n; i++){
        int b;  cin >> b;
        int d = min(b, a[i]);
        ans += d;
        b -= d;
        d = min(b, a[i+1]);
        ans += d;
        a[i+1] -= d;
    }
    cout << ans << endl;
    return 0;
}