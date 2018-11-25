#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

int main(){
    string s;
    cin >> s;

    vector<ll> v(4, 0);
    v[0] = 1;

    for(int i = 0; i < s.length(); i++){
        vector<ll> next = v;
        if(s[i] == 'A' || s[i] == '?') next[1] += v[0];
        if(s[i] == 'B' || s[i] == '?') next[2] += v[1];
        if(s[i] == 'C' || s[i] == '?') next[3] += v[2];
        if(s[i] == '?'){
            for(int j = 0; j < 4; j++){
                next[j] += 2*v[j];
            }
        }
        for(int j = 0; j < 4; j++){
            next[j] %= mod;
        }
        v = next;
    }

    cout << v[3] << endl;

    return 0;
}