#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    sort(v.rbegin(), v.rend());
    ll ret = 0;
    for(int i = 0; i < n; i++){
        if(k){
            k--;
            continue;
        }
        ret += v[i];
    }
    cout << ret << endl;
    return 0;
}