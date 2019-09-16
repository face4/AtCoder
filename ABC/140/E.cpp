#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<set>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> p(n), inv(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
        inv[p[i]-1] = i;
    }
    set<int> ind;
    ind.insert(inv[n-1]);
    ind.insert(-1); ind.insert(n);
    ll ans = 0;
    for(int i = n-2; i >= 0; i--){
        int center = inv[i];
        set<int>::iterator r = ind.upper_bound(center);
        set<int>::iterator l = r;
        l--;
        set<int>::iterator l2 = l;
        l2--;
        set<int>::iterator r2 = r;
        r2++;
        if((*l) == -1){
            ans += (ll)(center+1)*((*r2)-(*r))*(i+1);
        }else if((*r) == n){
            ans += (ll)((*l)-(*l2))*(n-center)*(i+1);
        }else{
            ans += (ll)((*l)-(*l2))*((*r)-center)*(i+1);
            ans += (ll)(center-(*l))*((*r2)-(*r))*(i+1);
        }
        ind.insert(center);
    }
    cout << ans << endl;
    return 0;
}