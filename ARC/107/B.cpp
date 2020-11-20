#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
#define inRange(x,a,b) (a <= x && x <= b)

int main(){
    int n, k;
    cin >> n >> k;
    vector<ll> v(2*n+1, 0);
    for(int i = 2; i <= 2*n; i++){
        v[i] = min(n, i-1)-max(i-n, 1)+1;
    }
    ll ans = 0;
    for(int i = 2; i <= 2*n; i++){
        if(inRange(i-k, 0, 2*n))  ans += v[i]*v[i-k];
    }
    cout << ans << endl;
    return 0;
}