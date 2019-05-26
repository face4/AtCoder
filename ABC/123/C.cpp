#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll n, a[5];
    cin >> n;
    for(int i = 0; i < 5; i++)  cin >> a[i];

    ll ans = (n+a[0]-1)/a[0];
    for(int i = 1; i < 5; i++){
        if(a[i] > a[i-1]){
            ans++;
        }else{
            ans = max(ans+1, i + (n+a[i]-1)/a[i]);
        }
    }

    cout << ans << endl;
    
    return 0;
}