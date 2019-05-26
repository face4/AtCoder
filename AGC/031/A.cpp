#include<iostream>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int main(){
    int n;
    string s;
    cin >> n >> s;

    int cnt[26] = {};
    for(char c : s) cnt[c-'a']++;

    ll ans = 1;
    for(int i = 0; i < 26; i++) ans *= (cnt[i]+1), ans %= mod;
    cout << (ans-1+mod)%mod << endl;
    
    return 0;
}