#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    int n;
    ll T;
    cin >> n >> T;

    ll ans = 0;
    ll before, after;  
    cin >> before;
    
    for(int i = 1; i < n; i++){
        cin >> after;
        ans += min(after-before, T);
        before = after;
    }

    ans += T;

    cout << ans << endl;

    return 0;
}