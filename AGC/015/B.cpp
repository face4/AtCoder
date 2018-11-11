#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;

    ll n = s.length();
    ll ans = n*(n-1);

    for(int i = 0; i < n; i++){
        if(s[i] == 'U') ans += i;
        if(s[i] == 'D') ans += n-i-1;
    }

    cout << ans << endl;
    
    return 0;
}