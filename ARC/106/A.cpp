#include<iostream>
#include<map>
using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin >> n;
    map<ll,int> s;
    ll x = 3;
    for(int i = 1; x <= n; i++){
        s[x] = i;
        x *= 3;
    }
    x = 5;
    for(int i = 1; x <= n; i++){
        if(s.count(n-x)){
            cout << s[n-x] << " " << i << endl;
            return 0;
        }
        x *= 5;
    }
    cout << -1 << endl;
    return 0;
}