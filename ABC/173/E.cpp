#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

int main(){
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    sort(v.begin(), v.end());
    ll ans = 1;
    if(k == n){
        for(int i = 0; i < k; i++)  ans = ans*(v[i]+mod)%mod;
    }else if(v.back() < 0 && k%2==1){
        for(int i = 0; i < k; i++)  ans = ans*(v[n-1-i]+mod)%mod;
    }else{
        priority_queue<ll> p, m;
        for(int i = 0; i < n; i++)  (v[i] >= 0 ? p : m).push(abs(v[i]));
        if(k%2) k--, ans = ans*p.top()%mod, p.pop();
        while(k){
            if(p.size() < 2){
                ans = ans*m.top()%mod;  m.pop();
                ans = ans*m.top()%mod;  m.pop();
            }else if(m.size() < 2){
                ans = ans*p.top()%mod;  p.pop();
                ans = ans*p.top()%mod;  p.pop();
            }else{
                ll a = p.top(); p.pop();
                ll b = p.top(); p.pop();
                ll c = m.top(); m.pop();
                ll d = m.top(); m.pop();
                if(a*b > c*d){
                    ans = ans*a%mod*b%mod;
                    m.push(c);  m.push(d);
                }else{
                    ans = ans*c%mod*d%mod;
                    p.push(a);  p.push(b);
                }
            }
            k -= 2;
        }
    }
    cout << ans << endl;
    return 0;
}