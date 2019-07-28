#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)  cin >> a[i];
    ll x = a[0];
    for(int i = 1; i < n; i++){
        if(i%2) x -= a[i];
        else    x += a[i];
    }
    x /= 2;
    vector<ll> ans(n);
    ans[0] = x;
    for(int i = 1; i < n; i++){
        ans[i] = a[i-1] - ans[i-1];
    }
    for(int i = 0; i < n; i++)  cout << 2*ans[i] << " \n"[i+1 == n];
    return 0;
}