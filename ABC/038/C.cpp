#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;

    int A[n];
    for(int i = 0; i < n; i++)  cin >> A[i];

    ll l = 0, r = 0;
    ll ans = 0;

    while(r < n){
        while(r+1 < n && A[r+1] > A[r]) r++;

        if(l == r)  ans++;
        else        ans += (r-l+1)*(r-l)/2 + r-l+1;

        r++;
        l = r;
    }

    cout << ans << endl;
    return 0;
}
