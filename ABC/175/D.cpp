#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n, k;
    cin >> n >> k;
    int p[n];
    for(int i = 0; i < n; i++)  cin >> p[i], p[i]--;
    ll c[n];
    for(int i = 0; i < n; i++)  cin >> c[i];
    ll ans = *max_element(c, c+n);
    for(int i = 0; i < n; i++){
        bool b[5000] = {};
        int pos = p[i];
        ll acc = 0;
        vector<ll> v;
        while(!b[pos]){
            b[pos] = true;
            acc += c[pos];
            pos = p[pos];
            v.push_back(acc);
        }
        int siz = v.size();
        if(v.back() <= 0){
            ans = max(ans, *max_element(v.begin(), v.begin()+min(siz, k)));
        }else{
            ll loop = k/siz - (k%siz==0);
            ll res = k - loop*siz;
            ll tmp = loop*v.back();
            ans = max(ans, tmp+*max_element(v.begin(), v.begin()+res));
        }
    }
    cout << ans << endl;
    return 0;
}