#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)  cin >> a[i];
    ll sum = accumulate(a.begin(), a.end(), 0ll);
    if(sum%(n*(n+1)/2)){
        cout << "NO" << endl;
        return 0;
    }
    ll k = sum / (n*(n+1)/2);
    for(int i = 0; i < n; i++){
        ll diff = a[i]-a[(i+n-1)%n]-k;
        if(diff > 0 || abs(diff)%n > 0){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}