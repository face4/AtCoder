#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

ll f(ll n){
    return n*(n-1)/2;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n), cnt(n, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        cnt[--a[i]]++;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += f(cnt[i]);
    }
    for(int i = 0; i < n; i++){
        cout << ans-f(cnt[a[i]])+f(cnt[a[i]]-1) << endl;
    }
    return 0;
}