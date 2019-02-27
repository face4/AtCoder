#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    int n, k;   cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++)  cin >> a[i];
    vector<ll> v(k+1, 0);
    v[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = k-a[i]; j >= 0; j--){
            v[j+a[i]] += v[j];
        }
    }
    int ans = n;
    for(int i = 0; i < n; i++){
        vector<ll> cp = v;
        for(int j = a[i]; j <= k; j++)  cp[j] -= cp[j-a[i]];
        bool flag = false;
        for(int j = max(0, k-a[i]); j <= k-1; j++){
            if(cp[j])   flag = true;
        }
        if(flag)    ans--;
    }
    cout << ans << endl;
    return 0;
}