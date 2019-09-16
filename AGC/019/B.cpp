#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    ll n = s.length();
    ll ans = n*(n-1)/2;
    vector<ll> cnt(26, 0);
    for(char c : s) cnt[c-'a']++;
    for(int i = 0; i < 26; i++){
        ans -= cnt[i]*(cnt[i]-1)/2;
    }
    cout << ans+1 << endl;
    return 0;
}