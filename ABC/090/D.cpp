#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    int n, k;
    cin >> n >> k;

    ll ans = 0;
    for(int b = k+1; b <= n; b++){
        int segment = n / b;
        ans += (ll)segment * (b-k) + (ll)max(0, n%b+1-k) - (k == 0);
        // k==0 を引いているのは、k==0のときにカウントされてしまうa==0のパターンを相殺するため
    }

    cout << ans << endl;

    return 0;
}