#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    int a[n+1];
    for(int i = 0; i <= n; i++)  cin >> a[i];
    if(n == 0){
        cout << (a[0]==1 ? 1 : -1) << endl;
        return 0;
    }else if(a[0] == 1){
        cout << (accumulate(a, a+n+1, 0ll) == 1 ? 1 : -1) << endl;
        return 0;
    }else if(a[0] > 1){
        cout << -1 << endl;
        return 0;
    }
    ll sum = accumulate(a, a+n+1, 0ll);
    ll ans = 1, avail = 1;
    for(int i = 1; i <= n; i++){
        if(i == n){
            if(avail*2 >= a[i]){
                cout << ans+a[i] << endl;
            }else{
                cout << -1 << endl;
            }
            return 0;
        }
        if(avail*2 < a[i]){
            cout << -1 << endl;
            return 0;
        }
        avail *= 2;
        avail = min(avail, sum);
        ans += avail;
        if(a[i] > 0){
            avail -= a[i];
            sum -= a[i];
        }
    }
}