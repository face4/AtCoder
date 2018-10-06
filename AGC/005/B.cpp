#include<iostream>
#include<set>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;

    int a[n], rev[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        rev[a[i]-1] = i;
    }

    set<int> pos;
    
    // sentinel
    pos.insert(-1);
    pos.insert(n);

    ll ans = 0;
    for(int i = 0; i < n; i++){
        set<int>::iterator l = pos.lower_bound(rev[i]);
        set<int>::iterator r = l;
        l--;
        ans += (ll)(rev[i]-(*l)) * ((*r)-rev[i]) * (i+1);
        pos.insert(rev[i]);
    }

    cout << ans << endl;

    return 0;
}