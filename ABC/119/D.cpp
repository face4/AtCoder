#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int a, b, q;
    cin >> a >> b >> q;

    vector<ll> s(a), t(b);
    for(int i = 0; i < a; i++)  cin >> s[i];
    for(int i = 0; i < b; i++)  cin >> t[i];

    ll x;
    while(q-- > 0){
        cin >> x;
        vector<ll> shrine, temple;
        auto ls = lower_bound(s.begin(), s.end(), x);
        auto rs = ls;
        if(ls != s.begin()) ls--;
        shrine.push_back(*ls);  
        shrine.push_back(*rs);  
        
        auto lt = lower_bound(t.begin(), t.end(), x);
        auto rt = lt;
        if(lt != t.begin()) lt--;
        temple.push_back(*lt);
        temple.push_back(*rt);

        ll dist = 1ll<<60;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                if( ((x-temple[i])>0&&(x-shrine[j])>0) || ((x-temple[i])<0&&(x-shrine[j])<0)){
                    dist = min(dist, max(abs(x-temple[i]), abs(x-shrine[j])));
                }else{
                    ll tmpa = abs(x-temple[i]), tmpb = abs(x-shrine[j]);
                    if(tmpa > tmpb) swap(tmpa, tmpb);
                    dist = min(dist, 2*tmpa+tmpb);
                }
            }
        }
        cout << dist << endl;
    }

    return 0;
}
