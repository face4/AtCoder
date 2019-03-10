#include<iostream>
#include<set>
using namespace std;
typedef long long ll;

ll f(ll n, ll b){
    ll ret = 0;
    while(n){
        ret += n%b;
        n /= b;
    }
    return ret;
}

int main(){
    ll n, s;
    cin >> n >> s;
    
    if(n <= s){
        cout << (n == s ? n+1 : -1)<< endl;
        return 0;
    }

    for(ll b = 2; b*b <= n; b++){
        if(f(n, b) == s){
            cout << b << endl;
            return 0;
        }
    }

    set<ll> ans;
    for(ll b = 2; (b-1)*(b-1) <= n-s; b++){
        if((n-s)%(b-1) == 0){
            ans.insert(b);
            ans.insert((n-s)/(b-1)+1);
        }
    }

    for(ll v : ans){
        if(f(n, v) == s){
            cout << v << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}