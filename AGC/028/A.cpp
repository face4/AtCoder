#include<iostream>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a%b);
}

int main(){
    ll n, m;
    string s, t;
    
    cin >> n >> m >> s >> t;

    if(s[0] != t[0]){
        cout << -1 << endl;
        return 0;
    }

    ll g = gcd(n, m);
    ll l = n*m/g;

    if(g != 1){
        bool judge = true;
        int apos = 0, bpos = 0;
        while(apos < n && bpos < m){
            if(s[apos] != t[bpos])  judge = false;
            apos += n/g;
            bpos += m/g;
        }
        if(judge)   cout << l << endl;
        else        cout << -1 << endl;
    }else{
        cout << l << endl;
    }

    return 0;
}