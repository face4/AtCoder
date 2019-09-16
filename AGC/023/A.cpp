#include<iostream>
#include<map>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    map<ll,ll> m;
    m[0]++;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        sum += x;
        m[sum]++;
    }
    ll ans = 0;
    for(auto p : m){
        ans += (p.second)*(p.second-1)/2;
    }
    cout << ans << endl;
    return 0;
}